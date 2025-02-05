#include "SaveFileManager.h"

SaveFileManager::SaveFileManager(const std::string& filename) {
	name = filename;
	try {
		file.open(filename, std::ios::in | std::ios::out);
		// Si le fichier n'existe pas, il est cr�e avec une sauvegarde par d�faut
		if (!file) {
			file.clear();
			file.open(filename, std::ios::out);
			write(0);
			file.close();
			file.open(filename, std::ios::in | std::ios::out);
			exists = false;
		}
		// Sinon, on v�rifie si il est vide
		else {
			file.seekg(0, std::ios::end);
			if (file.tellg() == 0) {
				file.close();
				file.open(filename, std::ios::out);
				write(0);
				file.close();
				file.open(filename, std::ios::in | std::ios::out);
				exists = false;
			}
			else {
				exists = true;
			}
		}
		// Enfin, on lit les valeurs
		read();
	}
	catch (std::exception& error) {
		std::cerr << "Erreur survenue lors du chargement du fichier : " << error.what() << '\n';
	}
}

SaveFileManager::~SaveFileManager() {
	if(file.is_open())
		file.close();
}

void SaveFileManager::associateValue(std::string value, std::string category) {
	if (category == "NAME") {
		if (name == "Saves/saveSlotOne.txt")
			Shared::saveNameOne = value;
		else if (name == "Saves/saveSlotTwo.txt")
			Shared::saveNameTwo = value;
		else if (name == "Saves/saveSlotThree.txt")
			Shared::saveNameThree = value;
	}
	else if (category == "HEARTS") {
		if (name == "Saves/saveSlotOne.txt")
			Shared::numberOfHeartsOne = stoi(value);
		else if (name == "Saves/saveSlotTwo.txt")
			Shared::numberOfHeartsTwo = stoi(value);
		else if (name == "Saves/saveSlotThree.txt")
			Shared::numberOfHeartsThree = stoi(value);
	}
	else if (category == "POSITION") {
		std::string xPos, yPos;
		size_t spacing = value.find(' ');
		if (spacing != std::string::npos && value.find(' ', spacing + 1) == std::string::npos) {
			xPos = value.substr(0, spacing);
			yPos = value.substr(spacing + 1);
		}
		if (name == "Saves/saveSlotOne.txt") {
			Shared::savedPosOne.x = (float)stoi(xPos);
			Shared::savedPosOne.y = (float)stoi(yPos);
		}
		else if (name == "Saves/saveSlotTwo.txt") {
			Shared::savedPosTwo.x = (float)stoi(xPos);
			Shared::savedPosTwo.y = (float)stoi(yPos);
		}
		else if (name == "Saves/saveSlotThree.txt") {
			Shared::savedPosThree.x = (float)stoi(xPos);
			Shared::savedPosThree.y = (float)stoi(yPos);
		}
	}
	else if (category == "RUBIS") {
		if (name == "Saves/saveSlotOne.txt")
			Shared::numberOfRubisOne = stoi(value);
		else if (name == "Saves/saveSlotTwo.txt")
			Shared::numberOfRubisTwo = stoi(value);
		else if (name == "Saves/saveSlotThree.txt")
			Shared::numberOfRubisThree = stoi(value);
	}
	else if (category == "BOCAL") {
		if (name == "Saves/saveSlotOne.txt") {
			if (value == "-1")
				Shared::hasBocalOne = -1;
			else if (value == "0")
				Shared::hasBocalOne = 0;
			else if (value == "1")
				Shared::hasBocalOne = 1;
		}
		else if (name == "Saves/saveSlotTwo.txt") {
			if (value == "-1")
				Shared::hasBocalTwo = -1;
			else if (value == "0")
				Shared::hasBocalTwo = 0;
			else if (value == "1")
				Shared::hasBocalTwo = 1;
		}
		else if (name == "Saves/saveSlotThree.txt") {
			if (value == "-1")
				Shared::hasBocalThree = -1;
			else if (value == "0")
				Shared::hasBocalThree = 0;
			else if (value == "1")
				Shared::hasBocalThree = 1;
		}
	}
	else if (category == "LAST SAVE") {
		std::tm timeInfo;
		time_t valueToDecrypt = stoi(value);
		std::cout << value << std::endl;
		localtime_s(&timeInfo, &valueToDecrypt);
		std::stringstream st;
		st << std::put_time(&timeInfo, "%d/%m/%Y %H:%M");
		std::string current = st.str();
		if (name == "Saves/saveSlotOne.txt")
			Shared::lastSaveTimeOneString = current;
		else if (name == "Saves/saveSlotTwo.txt")
			Shared::lastSaveTimeTwoString = current;
		else if (name == "Saves/saveSlotThree.txt")
			Shared::lastSaveTimeThreeString = current;
	}
	else if (category == "PLAYTIME") {
		if (name == "Saves/saveSlotOne.txt")
			Shared::playTimeOne = value;
		else if (name == "Saves/saveSlotTwo.txt")
			Shared::playTimeTwo = value;
		else if (name == "Saves/saveSlotThree.txt")
			Shared::playTimeThree = value;
	}
}

void SaveFileManager::read() {
	file.clear();  // Clear any potential error state
	file.seekg(0, std::ios::beg); // Move to the beginning of the file

	while (std::getline(file, lineContent)) {
		// Stop reading if we reach "SAVE END" or if the file is empty
		if (lineContent == "SAVE END" || lineContent.empty()) {
			break;
		}

		// Name of the player
		else if (lineContent.substr(0, 4) == "NAME" && lineContent.size() > 5)
			associateValue(lineContent.substr(5), "NAME");

		// Number of hearts
		else if (lineContent.substr(0, 6) == "HEARTS" && lineContent.size() > 7)
			associateValue(lineContent.substr(7), "HEARTS");

		// Player position
		else if (lineContent.substr(0, 8) == "POSITION" && lineContent.size() > 9)
			associateValue(lineContent.substr(9), "POSITION");

		// Rubies
		else if (lineContent.substr(0, 5) == "RUBIS" && lineContent.size() > 6)
			associateValue(lineContent.substr(6), "RUBIS");

		// Bottle
		else if (lineContent.substr(0, 5) == "BOCAL" && lineContent.size() >= 10) {
			associateValue(lineContent.substr(6), "BOCAL");
		}

		// Save time
		else if (lineContent.substr(0, 9) == "LAST SAVE" && lineContent.size() >= 10) {
			associateValue(lineContent.substr(10), "LAST SAVE");
		}

		// Play time
		else if (lineContent.substr(0, 8) == "PLAYTIME" && lineContent.size() >= 13) {
			associateValue(lineContent.substr(9), "PLAYTIME");
		}
	}
}

void SaveFileManager::write(int saveCode) {
	if (saveCode == 0) { // Sauvagerde par d�faut (vide)
		file.close();
		file.open(name, std::ios::out | std::ios::trunc);
		file.close();
		return;
	}
	// Si Alt+F4 pendant la s�lection du nom, sauvegarde par d�faut cr�e quand m�me
	if (Shared::saveNameOne == "") {
		Shared::saveNameOne = "Link";
		Shared::numberOfHeartsOne = 3;
		Shared::savedPosOne = { 0, 0 };
		Shared::numberOfRubisOne = 0;
		Shared::hasBocalOne = -1;
		Shared::lastSaveTimeOne = 0;
		Shared::playTimeOne = "0:00";
	}
	if(Shared::saveNameTwo == "") {
		Shared::saveNameTwo = "Link";
		Shared::numberOfHeartsTwo = 3;
		Shared::savedPosTwo = { 0, 0 };
		Shared::numberOfRubisTwo = 0;
		Shared::hasBocalTwo = -1;
		Shared::lastSaveTimeTwo = 0;
		Shared::playTimeTwo = "0:00";
	}
	if (Shared::saveNameThree == "") {
		Shared::saveNameThree = "Link";
		Shared::numberOfHeartsThree = 3;
		Shared::savedPosThree = { 0, 0 };
		Shared::numberOfRubisThree = 0;
		Shared::hasBocalThree = -1;
		Shared::lastSaveTimeThree = 0;
		Shared::playTimeThree = "0:00";
	}
	if(saveCode == 1) {
		file.close();
		file.open("Saves/saveSlotOne.txt", std::ios::out | std::ios::trunc);
		file << "NAME "      << Shared::saveNameOne        << std::endl;
		file << "HEARTS "    << Shared::numberOfHeartsOne  << std::endl;
		file << "POSITION "  << (int)Shared::savedPosOne.x << " " << (int)Shared::savedPosOne.y << std::endl;
		file << "RUBIS "     << Shared::numberOfRubisOne   << std::endl;
		file << "BOCAL "     << Shared::hasBocalOne        << std::endl;
		file << "LAST SAVE " << Shared::lastSaveTimeOne    << std::endl;
		file << "PLAYTIME "  << Shared::playTimeOne        << std::endl;
		file << "SAVE END";
		file.close();
	}
	else if (saveCode == 2) {
		file.close();
		file.open("Saves/saveSlotTwo.txt", std::ios::out | std::ios::trunc);
		file << "NAME "      << Shared::saveNameTwo        << std::endl;
		file << "HEARTS "    << Shared::numberOfHeartsTwo  << std::endl;
		file << "POSITION "  << (int)Shared::savedPosTwo.x << " " << (int)Shared::savedPosTwo.y << std::endl;
		file << "RUBIS "     << Shared::numberOfRubisTwo   << std::endl;
		file << "BOCAL "     << Shared::hasBocalTwo        << std::endl;
		file << "LAST SAVE " << Shared::lastSaveTimeTwo    << std::endl;
		file << "PLAYTIME "  << Shared::playTimeTwo        << std::endl;
		file << "SAVE END";
		file.close();
	}
	else if (saveCode == 3) {
		file.close();
		file.open("Saves/saveSlotThree.txt", std::ios::out | std::ios::trunc);
		file << "NAME "      << Shared::saveNameThree        << std::endl;
		file << "HEARTS "    << Shared::numberOfHeartsThree  << std::endl;
		file << "POSITION "  << (int)Shared::savedPosThree.x << " " << (int)Shared::savedPosThree.y << std::endl;
		file << "RUBIS "     << Shared::numberOfRubisThree   << std::endl;
		file << "BOCAL "     << Shared::hasBocalThree        << std::endl;
		file << "LAST SAVE " << Shared::lastSaveTimeThree    << std::endl;
		file << "PLAYTIME "  << Shared::playTimeThree        << std::endl;
		file << "SAVE END";
		file.close();
	}
}