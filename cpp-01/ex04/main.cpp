/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:05:10 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/02 16:01:30 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	writeToFile(std::string fileName, std::string oldWord, std::string newWord)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		newFileName;
	std::string		buffer;

	inFile.open(fileName);
	if (!inFile.is_open())
		return (std::cout << "Couldn't open the file\n", -1);

	newFileName.append(fileName + ".replace");
	outFile.open(newFileName);
	if (!outFile.is_open())
		return (std::cout << "Couldn't create the output file\n", -1);

	while (inFile)
	{
		std::getline(inFile, buffer);
		if (!inFile)
			break;
		while (buffer.find(oldWord) != std::string::npos)
		{
			outFile << buffer.substr(0, buffer.find(oldWord)) << newWord;
			buffer = buffer.substr(buffer.find(oldWord) + oldWord.length());
		}
		if (buffer.find(oldWord) == std::string::npos)
			outFile << buffer;
		if (!inFile.eof())
			outFile << '\n';
	}
	inFile.close();
	outFile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Invalid number of args\n", -1);
	
	std::string	oldWord = argv[2];
	std::string	newWord = argv[3];

	if (oldWord.length() < 1)
		return (std::cout << "No word to replace\n", -1);
	if (newWord.length() < 1)
		return (std::cout << "No word to replace with\n", -1);
	if (writeToFile(argv[1], oldWord, newWord) < 0)
		return (-1);
	return (0);
}