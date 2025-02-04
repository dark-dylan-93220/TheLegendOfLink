#include "SaveFileManager.h"

SaveFileManager::SaveFileManager(const std::string& filename) {
	name = filename;
	try {
		file.open(filename, std::ios::in | std::ios::out);
		// Si le fichier n'existe pas, il est crée avec une sauvegarde par défaut
		if (!file) {
			file.clear();
			file.open(filename, std::ios::out);
			write(0);
			file.close();
			file.open(filename, std::ios::in | std::ios::out);
		}
		// Sinon, on vérifie si il est vide
		else {
			file.seekg(0, std::ios::end);
			if (file.tellg() == 0) {
				file.close();
				file.open(filename, std::ios::out);
				write(0);
				file.close();
				file.open(filename, std::ios::in | std::ios::out);
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
			if (value == "NONE")
				Shared::hasBocalOne = -1;
			else if (value == "EMPTY")
				Shared::hasBocalOne = 0;
			else if (value == "FULL")
				Shared::hasBocalOne = 1;
		}
		else if (name == "Saves/saveSlotTwo.txt") {
			if (value == "NONE")
				Shared::hasBocalTwo = -1;
			else if (value == "EMPTY")
				Shared::hasBocalTwo = 0;
			else if (value == "FULL")
				Shared::hasBocalTwo = 1;
		}
		else if (name == "Saves/saveSlotThree.txt") {
			if (value == "NONE")
				Shared::hasBocalThree = -1;
			else if (value == "EMPTY")
				Shared::hasBocalThree = 0;
			else if (value == "FULL")
				Shared::hasBocalThree = 1;
		}
	}
}

void SaveFileManager::read() {
	file.clear();  // Clear any potential error state
	file.seekg(0, std::ios::beg); // Move to the beginning of the file

	while (std::getline(file, lineContent)) {
		// Stop reading if we reach "SAVE END"
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
	}
}

void SaveFileManager::write(int saveCode) {
	file << "NAME Link"      << std::endl;
	file << "HEARTS 3"       << std::endl;
	file << "POSITION 10 10" << std::endl;
	file << "RUBIS 0"        << std::endl;
	file << "BOCAL NONE"     << std::endl;
	file << "SAVE END"       << std::endl;
}