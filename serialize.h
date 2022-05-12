#pragma once
#include"string.h"
#include"vector.hpp"
#include"Pair.hpp"
#include<fstream>

static void writeString(std::ofstream& outFile, const string& str) {
	int len = str.getSize();
	outFile.write((const char*)&len, sizeof(int));

	outFile.write(str.c_str(), sizeof(char) * len);
}

static string readString(std::ifstream& inFile) {
	int len = 0;
	inFile.read((char*)&len, sizeof(len));

	char* buff = new char[len + 1];
	inFile.read(buff, sizeof(char) * len);

	buff[len] = '\0';

	string toReturn(buff);

	delete[] buff;

	return toReturn;
}

static void writeVector(std::ofstream& outFile, const Vector<size_t>& v) {
	int len = v.getSize();
	outFile.write((const char*)&len, sizeof(int));

	for (size_t i = 0; i < v.getSize(); i++)
		outFile.write((const char*)&v[i], sizeof(size_t));
}

static Vector<size_t> readVector(std::ifstream& inFile) {
	int len = 0;
	inFile.read((char*)&len, sizeof(int));
	Vector<size_t> toReturn;
	size_t read = 0;

	for (size_t i = 0; i < len; i++) {
		inFile.read((char*)&read, sizeof(size_t));
		toReturn.pushBack(read);
	}

	return toReturn;
}

static void writeCommentsToFile(std::ofstream& outFile, const Pair<string, string>& p) {
	writeString(outFile, p.getFirst());
	writeString(outFile, p.getSecond());
}

static Pair<string, string> readCommentsFromFile(std::ifstream& inFile) {
	string fst = readString(inFile);
	string snd = readString(inFile);

	return { fst, snd };
}

static void writeRatesToFile(std::ofstream& outFile, const Pair<string, unsigned>& comments) {
	writeString(outFile, comments.getFirst());
	outFile.write((const char*)&comments.getSecond(), sizeof(comments.getSecond()));
}

static Pair<string, unsigned> readRatesFromFile(std::ifstream& inFile) {
	string fst = readString(inFile);
	unsigned rate = 0;
	inFile.read((char*)&rate, sizeof(rate));
	
	return { fst, rate };
}