#include "MetaFile.h"

MetaFile::MetaFile(const char* fileName, const char* atlasName)
	: m_infile(fileName), m_textureAtlas(atlasName)
{
	ReadMetaInfo();
}

void MetaFile::ReadMetaInfo()
{
	std::string textLine;
	std::string Read, Key, Value;
	std::size_t i;

	while (!m_infile.eof()) {
		std::stringstream LineStream;
		std::getline(m_infile, textLine);
		LineStream << textLine;
		LineStream >> Read;

		if (Read == "common")
		{
			//this holds common data
			while (!LineStream.eof())
			{
				std::stringstream Converter;
				LineStream >> Read;
				i = Read.find('=');
				Key = Read.substr(0, i);
				Value = Read.substr(i + 1);

				//assign the correct value
				Converter << Value;
				if (Key == "lineHeight")
					Converter >> m_infoData.LineHeight;
				else if (Key == "base")
					Converter >> m_infoData.Base;
				else if (Key == "scaleW")
					Converter >> m_infoData.Width;
				else if (Key == "scaleH")
					Converter >> m_infoData.Height;
				else if (Key == "pages")
					Converter >> m_infoData.Pages;
			}
		}
		else if (Read == "char")
		{
			//this is data for a specific char
			unsigned short CharID = 0;

			while (!LineStream.eof())
			{
				std::stringstream Converter;
				LineStream >> Read;
				i = Read.find('=');
				Key = Read.substr(0, i);
				Value = Read.substr(i + 1);

				//assign the correct value
				Converter << Value;
				if (Key == "id")
					Converter >> CharID;
				else if (Key == "x")
					Converter >> m_infoData.Chars[CharID].x;
				else if (Key == "y")
					Converter >> m_infoData.Chars[CharID].y;
				else if (Key == "width")
					Converter >> m_infoData.Chars[CharID].Width;
				else if (Key == "height")
					Converter >> m_infoData.Chars[CharID].Height;
				else if (Key == "xoffset")
					Converter >> m_infoData.Chars[CharID].XOffset;
				else if (Key == "yoffset")
					Converter >> m_infoData.Chars[CharID].YOffset;
				else if (Key == "xadvance")
					Converter >> m_infoData.Chars[CharID].XAdvance;
				else if (Key == "page")
					Converter >> m_infoData.Chars[CharID].Page;
			}
		}
	}
}


