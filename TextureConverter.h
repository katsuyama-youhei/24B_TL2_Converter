#pragma once
#include <string>

class TextureConverter
{
public:
	TextureConverter();
	~TextureConverter();

	void ConverterTextureWICToDDS(const std::string& filePath);

};

