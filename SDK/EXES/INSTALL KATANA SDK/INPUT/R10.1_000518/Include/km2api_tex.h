/*++

  COPYRIGHT        (C) NEC        Corporation 1997 - 1999

  All rights reserved by NEC Corporation. This program must be
  used solely for the purpose for which it was furnished by NEC
  Corporation. No part of this program may be reproduced or
  disclosed to others, in any form, without the prior written
  permission of NEC Corporation.
  Use of copyright notice does not evidence publication of this
  program.

  Author     :		T.Muto(NEC Software,Ltd.)
  Module Name:		km2api_tex.h

  Abstract:
	KAMUI = Kamui is abstruction model that is ultimate interface for PowerVR.
	'km2api_tex.h' define the function of texture memory manager.

  Environment:
	ANSI C Compiler.

  Notes:
	

  Revision History:

--*/

#if !defined(__kamui2_texture_api_h__)
#define __kamui2_texture_api_h__

/*++
kmCreateTextureSurface

proto type:
	KMSTATUS 
	kmCreateTextureSurface(
			PKMSURFACEDESC	pSurfaceDesc,
			KMINT32			nWidth, 
			KMINT32			nHeight, 
			KMTEXTURETYPE	nTextureType
		);

Description:
	�e�N�X�`���p��Surface���m�ۂ��܂��B

Arguments:
	OUT	pSurfaceDesc		KMSURFACEDESC �\���̗̂̈�������|�C���^�ł��B
							�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
							KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	IN	nWidth, nHeight		�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B
								MIPMAP���g�p����ꍇ�ɂ̓g�b�v���x���̃e�N�X�`���T�C�Y���w�肵�܂��B
								Twiddled, VQ, Palettized�Ȃǂ̐����`�e�N�X�`�����g�p����ꍇ�ɂ� 
									nWidth�Ɏw�肵���l�݂̂��g�p����܂��B
								�����`�e�N�X�`�����g�p����ꍇ�ɂ́AnWidth, nHeight���ɗL���ł��B
								HOLLY�͐����`�e�N�X�`���T�C�Y�Ƃ��� 8x8�`1024x1024�܂ł̃e�N�X�`�����g�p�ł��܂����A
								nWidth, nHeight�Ɏw�肷��l��,8, 16, 32, 64, 128, 256, 512, 1024��
								�����ꂩ�łȂ���΂Ȃ�܂���B

	IN	nTextureType		�e�N�X�`���̌`�����w�肵�܂��B
							�ȉ��̃J�e�S���R�[�h�A�s�N�Z���t�H�[�}�b�g�R�[�h����
							����I�яo���A�_���a(or)���ė^���܂�

								-�J�e�S���R�[�h
									KM_TEXTURE_TWIDDLED			// Twiddled�t�H�[�}�b�g
									KM_TEXTURE_TWIDDLED_MM		// Twiddled�t�H�[�}�b�gMipmap����
									KM_TEXTURE_VQ				// VQ���k�`��
									KM_TEXTURE_VQ_MM			// VQ���k�`��Mipmap����
									KM_TEXTURE_PALETTIZE4		// 4bpp�p���b�g�`��
									KM_TEXTURE_PALETTIZE4_MM	// 4bpp�p���b�g�`��Mipmap����
									KM_TEXTURE_PALETTIZE8		// 8bpp�p���b�g�`��
									KM_TEXTURE_PALETTIZE8_MM	// 8bpp�p���b�g�`��Mipmap����
									KM_TEXTURE_RECTANGLE		// ��`

								- �s�N�Z���t�H�[�}�b�g�R�[�h
									KM_TEXTURE_1555
									KM_TEXTURE_565
									KM_TEXTURE_4444
									KM_TEXTURE_YUV422
									KM_TEXTURE_BUMP
									KM_TEXTURE_8888

							��)  KM_TEXTURE_8888��KM_TEXTURE_PALETTIZE4or8�Ƃ̑g�ݍ��킹�̂ݗL���ł��B

Result:
		KMSTATUS_SUCCESS					�e�N�X�`���������m�ې���
		KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
		KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�
		KMSTATUS_INVALID_MIPMAPED_TEXTURE	MIPMAP�ł��Ȃ��e�N�X�`����MIPMAP���w�肵���B

--*/

KMSTATUS KMAPI
kmCreateTextureSurface(
		OUT	PKMSURFACEDESC	pSurfaceDesc,
		IN	KMINT32			nWidth, 
		IN	KMINT32			nHeight, 
		IN	KMTEXTURETYPE	nTextureType
	);

/*++
kmCreateCombinedTextureSurface

proto type:
	KMSTATUS 
	kmCreateCombinedTextureSurface(
			PKMSURFACEDESC	pSurfaceDesc1,
			PKMSURFACEDESC	pSurfaceDesc2,
			KMINT32			nWidth, 
			KMINT32			nHeight, 
			KMTEXTURETYPE	nTextureType
		);

Description:
	VQ�e�N�X�`���p��Surface�� 2�m�ۂ��܂��BnTextureType�ɂɐݒ肷��e�N�X�`���J�e�S����
	KM_TEXTURE_VQ,KM_TEXTURE_VQ_MM�̂ǂ��炩�łȂ���΂Ȃ�܂���B

Arguments:
	OUT	pSurfaceDesc1		KMSURFACEDESC �\���̗̂̈������ 1 �߂̃|�C���^�ł��B
							�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
							KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	OUT	pSurfaceDesc2		KMSURFACEDESC �\���̗̂̈������ 2 �߂̃|�C���^�ł��B
							�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
							KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	IN	nWidth, nHeight		�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B
							MIPMAP���g�p����ꍇ�ɂ̓g�b�v���x���̃e�N�X�`���T�C�Y���w�肵�܂��B
							HOLLY�͐����`�e�N�X�`���T�C�Y�Ƃ��� 8x8�`1024x1024�܂ł̃e�N�X�`�����g�p�ł��܂����A
							nWidth, nHeight�Ɏw�肷��l��,8, 16, 32, 64, 128, 256, 512, 1024��
							�����ꂩ�łȂ���΂Ȃ�܂���B

	IN	nTextureType		�e�N�X�`���̌`�����w�肵�܂��B
							�ȉ��̃J�e�S���R�[�h�A�s�N�Z���t�H�[�}�b�g�R�[�h����
							����I�яo���A�_���a(or)���ė^���܂�

								-�J�e�S���R�[�h
									KM_TEXTURE_VQ				// VQ���k�`��
									KM_TEXTURE_VQ_MM			// VQ���k�`��Mipmap����

								- �s�N�Z���t�H�[�}�b�g�R�[�h
									KM_TEXTURE_ARGB1555
									KM_TEXTURE_ARGB4444

Result:
		KMSTATUS_SUCCESS					�e�N�X�`���������m�ې���
		KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
		KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmCreateCombinedTextureSurface(
		OUT	PKMSURFACEDESC	pSurfaceDesc1,
		OUT	PKMSURFACEDESC	pSurfaceDesc2,
		IN	KMINT32			nWidth, 
		IN	KMINT32			nHeight, 
		IN	KMTEXTURETYPE	nTextureType
	);


/*++
kmLoadTexture

proto type:

	KMSTATUS
	kmLoadTexture(
			PKMSURFACEDESC pSurfaceDesc,
			PKMDWORD pTexture
		);

Description:
	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃e�N�X�`����ǂݍ��݂܂��B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B
	IN	pTexture		���C����������̃e�N�X�`���������|�C���^�ł��B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/
KMSTATUS KMAPI
kmLoadTexture(
	IN	PKMSURFACEDESC pSurfaceDesc,
	IN	PKMDWORD pTexture
	);

/*++
kmLoadTextureBlock

proto type:

	KMSTATUS KMAPI
	kmLoadTextureBlock(
		PKMSURFACEDESC	pSurfaceDesc,
		PKMDWORD		pTexture,
		KMUINT32		nBlockNum,
		KMUINT32		nBlockSize
	)

Description:
	kmCreateTextureSurface�ŃA���P�[�g�����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃e�N�X�`���u���b�N��ǂݍ��݂܂��B

	�e�N�X�`���f�[�^���������̃u���b�N�ɕ������ēǂݍ��݂܂��B
	����ɂ��A���C����������ɑ傫�ȃ��[�N�G���A���m�ۂ��邱�ƂȂ��A
	�T�C�Y�̑傫�ȃe�N�X�`����ǂݍ��ނ��Ƃ��ł��܂��B

	�e�N�X�`���S�̂̃T�C�Y���u���b�N�T�C�Y�Ŋ���؂�Ȃ��Ă��A�������ǂݍ��܂�܂��B

	�ǂݍ��ރe�N�X�`���̃t�H�[�}�b�g�`���A�T�C�Y�Ȃǂ́ApSurfaceDesc
	���w���T�[�t�F�X�f�B�X�N���v�^��蔻�f���܂��B
	���ۂ̃e�N�X�`���̃t�H�[�}�b�g�`���Ȃǂ��ApSurfaceDesc���w���T�[�t�F�X�f�B�X�N���v�^
	�̓��e�ƈقȂ��Ă���ꍇ�́A�\�����s���ƂȂ�܂��B

	�Ȃ��A���̊֐���Small VQ�`���̃e�N�X�`���ɂ͑Ή����Ă��܂���B
	Small VQ�`����pSurfaceDesc���w�肵���ꍇ�ɂ́AKMSTATUS_INVALID_TEXTURE_TYPE��Ԃ��܂��B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface/kmCreateCombinedTextureSurface��
						�A���P�[�g�����e�N�X�`���T�[�t�F�X�ł��B
	IN	pTexture		���C����������̃e�N�X�`���u���b�N�̐擪�������|�C���^�ł��B
	IN	nBlockNum		�e�N�X�`���̃u���b�N�ԍ��� 0 ���� n ( n�̓t�H�[�}�b�g/�T�C�Y�ɂ��)�Ŏw�肵�܂��B
	IN	nBlockSize		�u���b�N�̃T�C�Y�� 32�o�C�g�P�ʂŎw�肵�܂��B
						�u���b�N�T�C�Y(�o�C�g)�� 32 �Ŋ������l���w�肵�Ă��������B
						�Ȃ��A�e�N�X�`���S�̂̃T�C�Y���u���b�N�T�C�Y�Ŋ���؂��K�v�͂���܂���B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_BLOCKNUMBER		�u���b�N�ԍ����s��
	KMSTATUS_INVALID_ADDRESS			�w�肳�ꂽ�A�h���X��擪�Ɏ��������u���b�N��
										�A���P�[�g����Ă��Ȃ�
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadTextureBlock(
	IN	PKMSURFACEDESC	pSurfaceDesc,
	IN	PKMDWORD		pTexture,
	IN	KMUINT32		nBlockNum,
	IN	KMUINT32		nBlockSize
	);

/*++
kmLoadTexturePart

proto type:

	KMSTATUS KMAPI
	kmLoadTexturePart(
			PKMSURFACEDESC	pSurfaceDesc,
			PKMDWORD		pTexture,
			KMUINT32		nOffset,
			KMUINT32		nSize
		)

Description:
	kmCreateTextureSurface�ŃA���P�[�g�����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃e�N�X�`��(����)��ǂݍ��݂܂��B

	�e�N�X�`���f�[�^���������̕����ɕ������ēǂݍ��݂܂��B
	����ɂ��A���C����������ɑ傫�ȃ��[�N�G���A���m�ۂ��邱�ƂȂ��A
	�T�C�Y�̑傫�ȃe�N�X�`����ǂݍ��ނ��Ƃ��ł��܂��B

	kmLoadTextureBlock�ƈقȂ�A��̃e�N�X�`�����A�u�T�C�Y�̈قȂ�v
	�����̕����ɕ����ēǂݍ��ނ��Ƃ��ł��܂��B�������A���܂łɓǂݍ���
	�e�N�X�`���̃T�C�Y(�擪����̃I�t�Z�b�g��)�́A���[�U���ŊǗ�����
	�K�v������܂��B

	�ǂݍ��ރe�N�X�`���̃t�H�[�}�b�g�`���A�T�C�Y�Ȃǂ́ApSurfaceDesc
	�Ŏw�肳���T�[�t�F�X�f�B�X�N���v�^��蔻�f����܂��B
	���ۂ̃e�N�X�`���̃t�H�[�}�b�g�`���Ȃǂ��ApSurfaceDesc�Ŏw�肳���
	�T�[�t�F�X�f�B�X�N���v�^�̓��e�ƈقȂ��Ă���ꍇ�́A�\�����s���ƂȂ�܂��B

	�Ȃ��A���̊֐���Small VQ�`���̃e�N�X�`���ɂ͑Ή����Ă��܂���B
	Small VQ�`����pSurfaceDesc���w�肵���ꍇ�ɂ́AKMSTATUS_INVALID_TEXTURE_TYPE��Ԃ��܂��B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface/kmCreateCombinedTextureSurface��
						�A���P�[�g�����e�N�X�`���T�[�t�F�X�ł��B
	IN	pTexture		���C����������̃e�N�X�`���u���b�N�̐擪�������|�C���^�ł��B
	IN	nOffset			���łɓǂݍ��񂾃e�N�X�`���̃T�C�Y(�擪����̃I�t�Z�b�g��)��
						�o�C�g�P�ʂŎw�肵�܂��B����́A����ǂݍ��ރe�N�X�`���f�[�^��
						�]�������A�e�N�X�`���̈�̐擪�A�h���X�ƂȂ�܂��B
	IN	nSize			����ǂݍ��ޕ����̃T�C�Y���o�C�g�P�ʂŎw�肵�܂��B
						�Ȃ��AnSize���A�e�N�X�`���̎c��T�C�Y ( = �e�N�X�`���T�C�Y - nOffset)
						���傫���ꍇ�́A�c��T�C�Y�݂̂𐳂����ǂݍ���Ő���I�����܂��B

Usage:
	nOffset = 0;
	nSize   = ***;
	pTexture�Ƀe�N�X�`���f�[�^�̍ŏ���nSize�o�C�g�����[�h;
	while(KMSTATUS_SUCCESS == kmLoadTexturePart(...);
		nOffset = nOffset + nSize;
		nSize   = ????;
		pTexture�Ɏ���nSize�o�C�g�����[�h;
	}

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_ADDRESS			nOffset���e�N�X�`���T�C�Y���z���Ă���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadTexturePart(
	IN	PKMSURFACEDESC	pSurfaceDesc,
	IN	PKMDWORD		pTexture,
	IN	KMUINT32		nOffset,
	IN	KMUINT32		nSize
	);


/*++
kmLoadRectangleTexturePart

proto type:

	KMSTATUS KMAPI
	kmLoadRectangleTexturePart(
			PKMSURFACEDESC	pSurfaceDesc,
			PKMDWORD		pTexture,
			KMUINT32		width,
			KMUINT32		height,
			KMUINT32		dst_X,
			KMUINT32		dst_Y,
			KMUINT32		src_X,
			KMUINT32		src_Y,
			KMUINT32		src_U
			)

Description:
	kmCreateTextureSurface�ŃA���P�[�g����Rectangle/Stride�`��
	�e�N�X�`����������̋�`�̈�ɁApTexture�Ŏw�肳�ꂽ���C��
	��������̃e�N�X�`���̋�`�̈�(����)���������݂܂��B

	Rectangle/Stride�`���e�N�X�`���̈ꕔ�����������邱�Ƃ��ł��܂��B

	�]����̋�`�̈�́A( dst_X, dst_Y )-( dst_X + width, dst_Y + height )�ł��B
	�]�����̋�`�̈�́A( src_X, src_Y )-( src_X + width, src_Y + height )�ł��B
	src_U���[���ł������ꍇ�́A�]�����e�N�X�`���̃T�C�Y�͋�`�̈�̕���
	����(width,height)�Ɠ��������̂Ƃ݂Ȃ��܂��B

	�Ȃ��A���̊֐���Rectangle/Stride�`���e�N�X�`���ɂ̂ݑΉ����Ă��܂��B
	�����ȊO��pSurfaceDesc���w�肵���ꍇ�ɂ́A
	KMSTATUS_INVALID_TEXTURE_TYPE��Ԃ��܂��B

	��`�̈�́A�]����E�]�����e�N�X�`���̗̈���Ɋ��S�Ɋ܂܂�Ă��Ȃ�
	��΂Ȃ�܂���B
	�����łȂ��ꍇ�ɂ́A�]����e�N�X�`�����܂߁A���̃e�N�X�`���̃f�[�^
	���j�󂳂��ꍇ������܂��B
	�_�Ђł́A���̃`�F�b�N�͍s���܂���B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface/kmCreateCombinedTextureSurface��
						�A���P�[�g����Rectangle/Stride�`���̃e�N�X�`���T�[�t�F�X�ł��B
						(�]����e�N�X�`��)
	IN	pTexture		���C����������̃e�N�X�`���f�[�^�̐擪�������|�C���^�ł��B
						(�]�����e�N�X�`��)
	IN	width,height	�]�������`�̈�̕��ƍ������e�N�Z�����Ŏw�肵�܂��B
	IN	dst_X,dst_Y		�]����e�N�X�`���ɉ������`�̈��X,Y���W�ł��B
						�]����e�N�X�`���̍���(�擪)�e�N�Z�������
						���΃e�N�Z�����Ŏw�肵�܂��B
	IN	src_X,src_Y		�]�����e�N�X�`���ɉ������`�̈��X,Y���W�ł��B
						�]�����e�N�X�`���̍���(�擪)�e�N�Z�������
						���΃e�N�Z�����Ŏw�肵�܂��B
	IN	src_U			�]�����e�N�X�`���̕����e�N�Z�����Ŏw�肵�܂��B
						���ꂪ�[���ł������ꍇ�́A�]�����e�N�X�`���̃T�C�Y��
						��`�̈�̕��ƍ���(width,height)�Ɠ��������̂Ƃ݂Ȃ��܂��B
						���̂Ƃ��́Asrc_X,src_Y�̒l�͖�������܂��B(0�Ƃ݂Ȃ���܂�)

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadRectangleTexturePart(
	IN	PKMSURFACEDESC	pSurfaceDesc,
	IN	PKMDWORD		pTexture,
	IN	KMUINT32		width,
	IN	KMUINT32		height,
	IN	KMUINT32		dst_X,
	IN	KMUINT32		dst_Y,
	IN	KMUINT32		src_X,
	IN	KMUINT32		src_Y,
	IN	KMUINT32		src_U
	);


/*++
kmFreeTexture

proto type:
	KMSTATUS
	kmFreeTexture(
			PKMSURFACEDESC pSurfaceDesc
		);

Description:
	�w�肵���e�N�X�`���T�[�t�F�X��������܂��B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B

Result:
	KMSTATUS_SUCCESS				�������
	KMSTATUS_INVALID_PARAMETER		������s�A�e�N�X�`���̎w�肪�s��

--*/

KMSTATUS KMAPI
kmFreeTexture(
	IN	PKMSURFACEDESC pSurfaceDesc
	);


/*++
kmGetFreeTextureMem

proto type:
	KMSTATUS
	kmGetFreeTextureMem(
		PKMUINT32 pSizeOfTexture,
		PKMUINT32 pMaxBlockSizeOfTexture
		);

Description:
	�e�N�X�`���������̎c�e�ʂ�Ԃ��܂��B

Arguments:
	OUT	pSizeOfTexture
			�e�N�X�`���������̎c�e�ʂ�Ԃ�KMDWORD�̈�ւ̃|�C���^�ł��B
	OUT	pMaxBlockSizeOfTexture
			�e�N�X�`���������̋󂫃u���b�N�̍ő�e�ʂ�Ԃ�KMDWORD�̈�ւ̃|�C���^�ł��B
Result:
	KMSTATUS_SUCCESS		����

--*/

KMSTATUS KMAPI
kmGetFreeTextureMem(
	OUT	PKMUINT32 pSizeOfTexture,
	OUT	PKMUINT32 pMaxBlockSizeOfTexture
	);

/*++
kmReLoadMipmap

proto type:
	KMSTATUS
	kmReLoadMipmap(
			PKMSURFACEDESC 	pSurfaceDesc,
			PKMVOID	 		pTexture,
			KMINT32	 		nMipmapCount
		);

Description:
	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`����������̗̈�ɁA 
	pTexture�Ŏw�肳�ꂽ���C����������̃~�b�v�}�b�v�e�N�X�`�����㏑���ǂݍ��݂��܂��B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B
						��Reload��ł���

	IN	pTexture		���C����������̃~�b�v�}�b�v�e�N�X�`���������|�C���^�ł��B
						��Reload���ł���

	IN	nMipmapCount	�ǂݍ��ރ~�b�v�}�b�v�e�N�X�`���̃��x�����w�肵�܂��B
						���L�̂����ꂩ���w�肷�邱�Ƃ��ł��܂��B

						nMipmapCount			Texture Size
						KM_MAPSIZE_1x1				   1x1
						KM_MAPSIZE_2x2				   2x2
						KM_MAPSIZE_4x4				   4x4
						KM_MAPSIZE_8x8				   8x8
						KM_MAPSIZE_16x16			  16x16
						KM_MAPSIZE_32x32			  32x32
						KM_MAPSIZE_64x64			  64x64
						KM_MAPSIZE_128x128			 128x128
						KM_MAPSIZE_256x256			 256x256
						KM_MAPSIZE_512x512			 512x512
						KM_MAPSIZE_1024x1024		1024x1024
	

Result:
	KMSTATUS_SUCCESS			����
	KMSTATUS_INVALID_PARAMETER	�p�����[�^���s��
	KMSTATUS_INVALID_TEXTURE	�����ȃe�N�X�`�����w�肵��

--*/
KMSTATUS KMAPI
kmReLoadMipmap(
	IN	PKMSURFACEDESC 	pSurfaceDesc,
	IN	PKMVOID		 	pTexture,
	IN	KMINT32	 		nMipmapCount
	);

/*++
kmGetTexture

proto type:

	KMSTATUS
	kmGetTexture(
		PKMDWORD		pTexture,
		PKMSURFACEDESC	pSurfaceDesc
		);

Description:
	pSurfaceDesc�Ŏw�肵���e�N�X�`����������̃e�N�X�`�����A 
	pTexture�Ŏw�肳�ꂽ���C����������ɓǂݏo���܂��B
	�o�͂ɂ́AKAMUI�e�N�X�`���t�H�[�}�b�g�ɏ]����16�o�C�g�̃w�b�_���t������܂��B

Arguments:
	OUT	pTexture		���C����������̃e�N�X�`����ۑ�����̈�������|�C���^�ł��B
	IN	pSurfaceDesc	�e�N�X�`�����ۑ�����Ă���e�N�X�`���T�[�t�F�X�ł��B

Result:
	KMSTATUS_SUCCESS					�ǂݏo������
	KMSTATUS_INVALID_ADDRESS			�w�肳�ꂽ�e�N�X�`���T�[�t�F�X��
										�m�ۂ���Ă��Ȃ�

--*/

KMSTATUS KMAPI
kmGetTexture(
	OUT	PKMDWORD		pTexture,
	IN	PKMSURFACEDESC	pSurfaceDesc
	);


/*++
kmGarbageCollectTexture

proto type:
	KMSTATUS
	kmGarbageCollectTexture( KMVOID );

Description:
	 Frame Buffer �������̃K�x�[�W�R���N�V�������s���܂��B

Arguments:

Result:
	KMSTATUS_SUCCESS					�K�x�[�W�R���N�V��������
	KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmGarbageCollectTexture( KMVOID );



/*++
kmSetFramebufferTexture

proto type:
	KMSTATUS 
	kmSetFramebufferTexture(
		IN	OUT	PKMSURFACEDESC	pSurfaceDesc
	);

Description:
	 Frame Buffer �̏����A�e�N�X�`���p��SurfaceDesc�ɓǂݏo���܂��B
	���O�� Frame Buffer �̓��e���AStride-Rectanglar-Texture�Ƃ���SurfaceDesc�ɐݒ肳��܂��B
	����SurfaceDesc���g�p���ăe�N�X�`���}�b�v���邱�Ƃɂ��A���O�� Frame Buffer 
	�̓��e���e�N�X�`���Ƃ��Ďg�p���邱�Ƃ��ł��܂��B
	�e�N�X�`���Ƃ��Ďg�p���悤�Ƃ��� Frame Buffer �́A���L�̐ݒ�ł���K�v������܂��B

	�EkmSetDisplayMode�ŁABitDepth �����L�̂��Âꂩ���w�肳��Ă��邱�ƁB
		KM_DSPBPP_ARGB1555
		KM_DSPBPP_RGB565

Arguments:
	IN	OUT	pSurfaceDesc	KMSURFACEDESC �\���̗̂̈�������|�C���^�ł��B
							 Frame Buffer �̏�񂪕Ԃ���܂��B

Result:
		KMSTATUS_SUCCESS				 Frame Buffer �̏��ǂݏo������
		KMSTATUS_INVALID_TEXTURE_TYPE	���݂� Frame Buffer �̐ݒ�̓e�N�X�`���Ƃ��Ďg�p�ł��Ȃ�

Sample:
	kmSetStrideWidth(nScreenWidth);					// Set screen width
	....(Setup vertex)....
	kmRender();										// Generate previous Frame-Buffer
	kmSetFramebufferTexture(pSurfaceDesc);			// Get Framebuffer information
	VertexContext.pTextureSurfaceDesc	= &pSurfaceDesc;
	kmProcessVertexRenderState(&VertexContext);		// Use Framebuffer as texture
	kmSetVertexRenderState(&VertexContext);			// Set new vertex-context
	....(Setup vertex)....
	kmRender();										// Render!!

--*/
#if 0
KMSTATUS KMAPI
kmSetFramebufferTexture(
		PKMSURFACEDESC	pSurfaceDesc
	);
#endif

/*++
kmLoadVQCodebook

proto type:

	KMSTATUS
	kmLoadVQCodebook(
			PKMSURFACEDESC pSurfaceDesc,
			PKMDWORD pTexture
		);

Description:
	pSurfaceDesc�Ŏw�肳�ꂽVQ�e�N�X�`���T�[�t�F�X�ɁApTexture�Ŏw�肳�ꂽ
	���C�����������VQ�e�N�X�`���̃R�[�h�u�b�N�����݂̂�ǂݍ��݂܂��B
	���[�h�ς݂�VQ�e�N�X�`���́A�R�[�h�u�b�N(800h�o�C�g)�݂̂�����������
	�J���[�p���b�g���ʂ��o�������Ƃ��Ɏg�p���܂��B

Arguments:
	IN	pSurfaceDesc	kmCreateTextureSurface�Ŋm�ۂ����e�N�X�`���T�[�t�F�X�ł��B
						���̃T�[�t�F�X�̃J�e�S���́AKM_TEXTURE_VQ�܂���KM_TEXTURE_VQ_MM
						�̂ǂ��炩�łȂ���΂Ȃ�܂���B
	IN	pTexture		���C����������̃e�N�X�`��(�R�[�h�u�b�N)�������|�C���^�ł��B
						����͊��S��VQ�e�N�X�`���ł���K�v�͂���܂��񂪁A
						���Ȃ��Ƃ��擪��800h�o�C�g�̃R�[�h�u�b�N���܂�ł���K�v������܂��B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadVQCodebook(
	IN	PKMSURFACEDESC	pSurfaceDesc,
	IN	PKMDWORD		pTexture
	);


/*++
kmCreateContiguousTextureSurface

proto type:
	KMSTATUS 
	kmCreateContiguousTextureSurface(
			PKMSURFACEDESC	pSurfaceDesc,
			KMINT32			nTexture,
			KMINT32			nWidth, 
			KMINT32			nHeight, 
			KMTEXTURETYPE	nTextureType
		);

Description:
	 Frame Buffer �̘A�������A�h���X�̈�ɁA�����ɕ����̃e�N�X�`���pSurface���m�ۂ��܂��B
	����́ATile Accelerator��YUV�R���o�[�^���g�p���āA�A�����ĕ�����YUV422�`���̃e�N�X�`��
	��ǂݍ��ނƂ��Ɏg�p���܂��B(kmLoadYUVTexture�����Q�Ƃ�������)
	YUV422�ȊO�̃e�N�X�`���pSurface�̊m�ۂɂ��g�p���邱�Ƃ��ł��܂��B

Arguments:
	OUT	pSurfaceDesc			KMSURFACEDESC �\���̂̔z��ւ̃|�C���^�ł��B
								�m�ۂ��� Texture Surface �̏�񂪕Ԃ���܂��B
								KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ�ɂ͕s��ƂȂ�܂��B

	IN	nTexture				�A�����Ċm�ۂ��� Texture Surface �̐����w�肵�܂��B

	IN	nWidth, nHeight			�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B
								nWidth, nHeight�Ɏw�肷��l��,8, 16, 32, 64, 128, 256, 512, 1024��
								�����ꂩ�łȂ���΂Ȃ�܂���B

	IN	nTextureType			�e�N�X�`���̌`�����w�肵�܂��B
								�ȉ��̃J�e�S���R�[�h�A�s�N�Z���t�H�[�}�b�g�R�[�h����
								����I�яo���A�_���a(or)���ė^���܂�

								-�J�e�S���R�[�h
									KM_TEXTURE_TWIDDLED				// Twiddled�t�H�[�}�b�g
									KM_TEXTURE_TWIDDLED_MM			// Twiddled�t�H�[�}�b�gMipmap����
									KM_TEXTURE_TWIDDLED_RECTANGLE	// Twiddled-Rectangle
									KM_TEXTURE_VQ					// VQ���k�t�H�[�}�b�g
									KM_TEXTURE_VQ_MM				// VQ���k�t�H�[�}�b�gMipmap����
									KM_TEXTURE_PALETTIZE4			// 4bpp�p���b�g�`��
									KM_TEXTURE_PALETTIZE4_MM		// 4bpp�p���b�g�`��Mipmap����
									KM_TEXTURE_PALETTIZE8			// 8bpp�p���b�g�`��
									KM_TEXTURE_PALETTIZE8_MM		// 8bpp�p���b�g�`��Mipmap����
									KM_TEXTURE_RECTANGLE			// ��`
									KM_TEXTURE_STRIDE				// ��`(�X�g���C�h�w��L��)

								- �s�N�Z���t�H�[�}�b�g�R�[�h
									KM_TEXTURE_ARGB1555
									KM_TEXTURE_RGB565
									KM_TEXTURE_ARGB4444
									KM_TEXTURE_YUV422
									KM_TEXTURE_BUMP

Result:
		KMSTATUS_SUCCESS					�e�N�X�`���������m�ې���
		KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
		KMSTATUS_NOT_ENOUGH_MEMORY			�������e�ʂ�����Ȃ�

--*/

KMSTATUS KMAPI
kmCreateContiguousTextureSurface(
	OUT		PKMSURFACEDESC	pSurfaceDesc,
	IN		KMINT32			nTexture,
	IN		KMINT32			nWidth,
	IN		KMINT32			nHeight,
	IN		KMTEXTURETYPE	nTextureType
	);


/*++
kmLoadYUVTexture

proto type:

	KMSTATUS
	kmLoadYUVTexture(
		PPKMSURFACEDESC	ppSurfaceDesc,
		PKMDWORD		pTexture,
		KMINT32			nWidth,
		KMINT32			nHeight,
		KMDWORD			nFormat,
		KMBOOLEAN		bWaitEndOfDMA
		);

Description:
	kmCreateTextureSurface/kmCreateCombinedTextureSurface/kmCreateContiguousTextureSurface
	�Ŋm�ۂ����e�N�X�`����������̗̈�ɁApTexture�Ŏw�肳�ꂽ���C�����������
	YUV420-data/YUV422-data���ANon-Twiddled YUV422�e�N�X�`���ɕϊ����ēǂݍ��݂܂��B
	Tile Accelerator �ɓ�������Ă��� YUV-data converter ���g�p���āA�ϊ����Ȃ���
	�ǂݍ��݂܂��B

	YUV-data converter �̏o�͂� Non-Twiddled �ł��邽�߁A����API�Ŏw�肷��ǂݍ��ݐ��
	Texture Surface �̌`���́A�ȉ��̂����ꂩ�łȂ���΂Ȃ�܂���B
		KM_TEXTURE_RECTANGLE | KM_TEXTURE_YUV422	// ��`
		KM_TEXTURE_STRIDE    | KM_TEXTURE_YUV422	// ��`(�X�g���C�h�w��L��)

	������YUV-data���A��x�ɘA�����ēǂݍ��ޏꍇ(nTexture > 1 �̎�)�́A�X�̃e�N�X�`����
	�T�C�Y��16x16�e�N�Z���łȂ���΂Ȃ�܂���B����API�Ŏw�肷��ǂݍ��ݐ��Texture Surface
	�̃T�C�Y�w��ɂ����ӂ��������B
	�܂��A���̏ꍇ�́A�ǂݍ��ݐ��Texture Surface�� Frame Buffer ��ŘA�������A�h���X��
	�m�ۂ���Ă��邱�Ƃ��K�v�ł��B"kmCreateContiguousTextureSurface" API���g�p����
	�m�ۂ���Texture Surface���w�肵�Ă��������B

Arguments:
	IN	ppSurfaceDesc	�A���P�[�g�ς݂̃e�N�X�`���T�[�t�F�X������KMSURFACEDESC �\���̂ւ�
						�|�C���^�z��̃|�C���^�ł��B
	IN	pTexture		���C�����������YUV420-data/YUV422-data�������|�C���^�ł��B
	IN	nWidth,
	IN	nHeight,
						�A�����ēǂݍ��� Texture �}�N���u���b�N�̐����c�Ɖ��̐��Ŏw�肵�܂��B
						�w��ł���l�́A���ꂼ�� 1 ���� 64 �̂����ꂩ�ł��B
	IN	nFormat			�ǂݍ��ރf�[�^�̌`�����w�肵�܂��B�ȉ��̂����ꂩ���w�肵�܂��B
						KM_TEXTURE_YUV420		���̓f�[�^��YUV420-data�ł��邱�Ƃ������܂��B
						KM_TEXTURE_YUV422		���̓f�[�^��YUV422-data�ł��邱�Ƃ������܂��B
	IN	bWaitEndOfDMA	TRUE�̏ꍇ�AYUV�R���o�[�^�ւ̃f�[�^�]����DMA����������̂�҂��܂��B
									DMA���I������܂ŁA�{API�͏I�����܂���B
						FALSE�̏ꍇ�ADMA�̏I����҂��܂���BDMA�̏I�������m�������ꍇ��
									�R�[���o�b�N"kmSetEndOfYUVCallback"���g�p���Ă��������B

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��

--*/

KMSTATUS KMAPI
kmLoadYUVTexture(
	IN	PKMSURFACEDESC	pSurfaceDesc,
	IN	PKMDWORD		pTexture,
	IN	KMINT32			nWidth,
	IN	KMINT32			nHeight,
	IN	KMDWORD			nFormat,
	IN	KMBOOLEAN		bWaitEndOfDMA
	);


/*++
kmCreateFixedTextureArea

proto type:

	KMSTATUS KMAPI
	kmCreateFixedTextureArea(
		OUT  PKMSURFACEDESC pSurfaceDesc,
		IN  KMINT32  nWidth,
		IN  KMINT32  nHeight,
		IN  KMTEXTURETYPE  nTextureType
		);

Description:
	kmSetSystemConfiguration �𔭍s���Ă������Ȃ��A�Œ�e�N�X�`���̈���m
	�ۂ��܂��B�Œ�e�N�X�`���̈�̓Q�[���S�̂Ŏg�p����t�H���g�e�N�X�`����
	�ǂ�u���̈�Ƃ��Ďg�p�ł��܂��B����Ŋm�ۂ����̈�� 
	kmFreeFixedTextureArea�֐��ł�������o���܂���B
	�܂��A�Œ�e�N�X�`���̈�̓V�X�e���ň�����m�ۂł��܂���B

	���ۂ̌Œ�e�N�X�`���̈�̊m�ۂ́A���� kmSetSystemConfiguration �𔭍s��
	���Ƃ��ɍs���܂��B���̊֐����s��́A�K�� kmSetSystemConfiguration ��
	�s����K�v������܂��B�܂��A�Œ�e�N�X�`���̈�ւ̃f�[�^�ǂݍ��݂́A
	 kmSetSystemConfiguration �̌�ɍs��Ȃ���΂Ȃ�܂���B
	���Ȃ킿�A�֐��̌Ăяo�������́A
	(1)kmCreateFixedTextureArea�ŌŒ�e�N�X�`���̈���m�ہB
	(2)kmSetSystemConfiguration���s�B���ۂ̌Œ�̈�m�ۂ͂����ōs����B
	(3)kmLoadTexture�ȂǂŁA�Œ�e�N�X�`���̈�փe�N�X�`���f�[�^��ǂݍ��ށB
	�ƂȂ�܂��B 

	kmSetSystemConfiguration �𔭍s����O�ɁAkmFreeFixedTextureArea �����s��
	�ꂽ�ꍇ�́A����܂łɔ��s���ꂽkmCreateFixedTextureArea�͖����ƂȂ�܂�
	�B���̏ꍇ�́A�Œ�e�N�X�`���̈�͊m�ۂ���܂���B 

	�Ȃ��A�����Ŋm�ۂ����̈�̓K�x�[�W�R���N�V�����̑ΏۂƂ͂Ȃ�܂���B�܂�
	�A�Œ�e�N�X�`���̈�̗e�ʂ͂S�l�a���z���邱�Ƃ͂ł��܂���B 

Arguments:
	OUT	pSurfaceDesc	KMSURFACEDESC�^�̍\���̂ւ̃|�C���^�ł��B
						���̍\���̂ɂ́A�_�Ђɂ����Surface��񂪕Ԃ���܂��B
						KMSTATUS ��KMSTATUS_NOT_ENOUGH_MEMORY���Ԃ��ꂽ�ꍇ��
						�͕s��ƂȂ�܂��B 
	IN	nWidth,nHeight	�e�N�X�`���̉��T�C�Y�A�c�T�C�Y���w�肵�܂��B MIPMAP��
						�g�p����ꍇ�ɂ̓g�b�v���x���̃e�N�X�`���T�C�Y���w��
						���܂��B�����`�e�N�X�`���T�C�Y��8x8�`1024x1024�܂ł�
						�e�N�X�`�����g�p�ł��܂����A nWidth, nHeight�Ɏw�肷
						��l��,8, 16, 32, 64, 128, 256, 512, 1024�̂����ꂩ��
						�Ȃ���΂Ȃ�܂���B 
	IN	nTextureType	�e�N�X�`���̌`�����w�肵�܂��B KmCreateTextureSurface
						�̐��������Q�Ƃ��������B 

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���
	KMSTATUS_INVALID_TEXTURE_TYPE		�����ȃe�N�X�`���^�C�v���w�肵��
	KMSTATUS_NOT_ENOUGH_MEMORY			�Œ�e�N�X�`���̈�̗e�ʂ��S�l�a���z���� 

--*/

KMSTATUS KMAPI
kmCreateFixedTextureArea(
	OUT	PKMSURFACEDESC	pSurfaceDesc,
	IN	KMINT32			nWidth,
	IN	KMINT32			nHeight,
	IN	KMTEXTURETYPE	nTextureType
	);


/*++
kmFreeFixedTextureArea

proto type:

	KMSTATUS KMAPI
	kmFreeFixedTextureArea( KMVOID ); 

Description:
	kmCreateFixedTextureArea �Ŋm�ۂ������ׂĂ̌Œ�e�N�X�`���̈���������
	���B
	���ۂ̌Œ�e�N�X�`���̈�̉���́A���� kmSetSystemConfiguration �𔭍s��
	���Ƃ��ɍs���܂��B���̊֐����s��́A�K�� kmSetSystemConfiguration ��
	�s����K�v������܂��B 
	���̊֐��ł́A kmCreateTextureSurface / kmCreateCombinedTextureSurface /
	kmCreateContiguousTextureSurface �Ŋm�ۂ����̈�͊J���ł��܂���B 

Arguments:
	None

Result:
	KMSTATUS_SUCCESS					�ǂݍ��ݐ���

--*/

KMSTATUS KMAPI
kmFreeFixedTextureArea( KMVOID ); 


/*++
kmGetCurrentTextureStatus

proto type:

	KMSTATUS KMAPI
	kmGetCurrentTextureStatus(
		OUT PKMFBSTATUS pFBStatus
		);

Description:
	�t���[���o�b�t�@�������̊Ǘ��Ɋւ������ǂݏo���܂��B���[�U�[�����L�\
	���̂��������A�����ւ̃|�C���^��n���ƁA���̊֐����e�����o�̓��e��ݒ肵
	�܂��B 

Arguments:
	OUT	pFBStatus		FB�Ǘ����\���̂ւ̃|�C���^ 

Result:
	KMSTATUS_SUCCESS					����

--*/

KMSTATUS KMAPI
kmGetCurrentTextureStatus(
	OUT PKMFBSTATUS pFBStatus
	);

#endif