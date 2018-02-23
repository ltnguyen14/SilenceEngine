#pragma once
#include <fstream>
#include <unordered_map>
#include <string>
#include <stdio.h>
#include <sstream>
#include "../../Tools/Texture/Texture.h"

struct CharDescriptor
{
	//clean 16 bytes
	unsigned short x, y;
	unsigned short Width, Height;
	float XOffset, YOffset;
	float XAdvance;
	unsigned short Page;

	CharDescriptor() : x(0), y(0), Width(0), Height(0), XOffset(0), YOffset(0),
		XAdvance(0), Page(0)
	{ }
};

struct Charset
{
	unsigned short LineHeight;
	unsigned short Base;
	unsigned short Width, Height;
	unsigned short Pages;
	CharDescriptor Chars[256];
};

class MetaFile {
public:
	MetaFile(const char* fileName, const char* atlasName);
	void ReadMetaInfo();
	Charset m_infoData;
	Texture m_textureAtlas;

	std::ifstream m_infile;
};