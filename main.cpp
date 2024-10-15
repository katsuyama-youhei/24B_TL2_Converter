#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include <Windows.h>

// �R�}���h���C������
enum Argument {
	kApplicationPath,	//	�A�v���P�[�V�����̃p�X 
	kFilePath,			//	�n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int main(int argc,char* argv[])
{

	assert(argc >= NumArgument);

	// COM ���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// �e�N�X�`���R���o�[�^
	TextureConverter textureConverter;
	// �e�N�X�`���ϊ�
	textureConverter.ConverterTextureWICToDDS(argv[kFilePath]);

	// COM ���C�u�����̏I��
	CoUninitialize();

	system("pause");
	return 0;

}