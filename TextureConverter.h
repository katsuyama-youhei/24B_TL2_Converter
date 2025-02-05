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
	/// �e�N�X�`����WI����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	/// <param name="numOptions">�I�v�V�����̐�</param>
	/// <param name="options">�I�v�V�����z��</param>
	void ConverterTextureWICToDDS(const std::string& filePath,int numOptions = 0,char* options[] = nullptr);

	/// <summary>
	/// 
	/// </summary>
	static void OutputUsage();

private:
	/// <summary>
	/// �e�N�X�`���t�@�C���̓ǂݍ���
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// �}���`�o�C�g����������C�h������ɕϊ�
	/// </summary>
	/// <param name="mString">�}���`�o�C�g������</param>
	/// <returns>���C�h������</returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	/// <summary>
	/// �t�H���_�p�X�ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath"></param>
	void SeparateFilePath(const std::wstring& filePath);

	/// <summary>
	/// DDS�e�N�X�`���Ƃ��ăt�@�C�������o��
	/// <param name="numOptions">�I�v�V�����̐�</param>
	/// <param name="options">�I�v�V�����z��</param>
	/// </summary>
	void SaveDDSTextureToFile(int numOptions,char* options[]);

private:
	// �摜�̏��
	DirectX::TexMetadata metadata_;
	// �摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;
	// �f�B���N�g���p�X
	std::wstring directoryPath_;
	// �t�@�C����
	std::wstring fileName_;
	// �t�@�C���g���q
	std::wstring fileExt_;
};

