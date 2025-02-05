#pragma once
#include <string>
#include <filesystem>
#include "Externals/DirectXTex/DirectXTex.h"
#include "Externals/DirectXTex/d3dx12.h"

using namespace DirectX;

class TextureConverter
{
public:
	TextureConverter();
	~TextureConverter();

	/// <summary>
	/// テクスチャをWIからDDSに変換する
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	/// <param name="numOptions">オプションの数</param>
	/// <param name="options">オプション配列</param>
	void ConverterTextureWICToDDS(const std::string& filePath,int numOptions = 0,char* options[] = nullptr);

	/// <summary>
	/// 
	/// </summary>
	static void OutputUsage();

private:
	/// <summary>
	/// テクスチャファイルの読み込み
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// マルチバイト文字列をワイド文字列に変換
	/// </summary>
	/// <param name="mString">マルチバイト文字列</param>
	/// <returns>ワイド文字列</returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	/// <summary>
	/// フォルダパスとファイル名を分離する
	/// </summary>
	/// <param name="filePath"></param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDSテクスチャとしてファイル書き出し
	/// <param name="numOptions">オプションの数</param>
	/// <param name="options">オプション配列</param>
	/// </summary>
	void SaveDDSTextureToFile(int numOptions,char* options[]);

private:
	// 画像の情報
	DirectX::TexMetadata metadata_;
	// 画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;
	// ディレクトリパス
	std::wstring directoryPath_;
	// ファイル名
	std::wstring fileName_;
	// ファイル拡張子
	std::wstring fileExt_;
};

