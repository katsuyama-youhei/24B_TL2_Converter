#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include <Windows.h>

// コマンドライン引数
enum Argument {
	kApplicationPath,	//	アプリケーションのパス 
	kFilePath,			//	渡されたファイルのパス

	NumArgument
};

int main(int argc,char* argv[])
{

	assert(argc >= NumArgument);

	// COM ライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// テクスチャコンバータ
	TextureConverter textureConverter;
	// テクスチャ変換
	textureConverter.ConverterTextureWICToDDS(argv[kFilePath]);

	// COM ライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;

}