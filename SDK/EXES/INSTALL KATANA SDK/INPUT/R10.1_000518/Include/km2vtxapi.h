/*++

  COPYRIGHT        (C) NEC        Corporation 1997 - 1999

  All rights reserved by NEC Corporation. This program must be
  used solely for the purpose for which it was furnished by NEC
  Corporation. No part of this program may be reproduced or
  disclosed to others, in any form, without the prior written
  permission of NEC Corporation.
  Use of copyright notice does not evidence publication of this
  program.

  Author     :		T.Kamei(NEC Software,Ltd.)
  Module Name:		km2vtxapi.h

  Abstract:
	KAMUI = Kamui is abstruction model that is ultimate interface for PowerVR.
	'km2vtxapi.h' define the function which manage vertex strip ,generate strip head ,
	process vertex context and is related with vertex strip.

  Environment:
	ANSI C Compiler.

  Notes:

  Revision History:

--*/

#if !defined(__kamui2_vertex_api_h__)
#define __kamui2_vertex_api_h__
/*++
kmGenerateStripHead

proto type:
	KMSTATUS KMAPI
	kmGenerateStripHead(
	        OUT PKMSTRIPHEAD        pStripHead,
	        IN  PKMSTRIPCONTEXT     pStripContext,
			IN  KMVERTEXTYPE		nVertexType
		);

Description:
	pStripContext �̓��e�����ɁAnVertexType �Ŏw�肳�ꂽ���_�^�C�v�ɂ����A
	KMSTRIPHEAD ���쐬�� pStripHead �������̈�ɏ������݂܂��B

	���̂́A kmGenerateStripHeadxx() �ւ̃f�B�X�p�b�`���ł��B
	�g�p���钸�_�^�C�v�����܂��Ă���ꍇ�ɂ�kmGenerateStripHeadxx()��
	�g�p�����ق����኱�����ł�(xx : 00 - 17 �̔C�ӂ̐��l)�B

Arguments:
	OUT pStripHead		������� KMSTRIPHEAD���������ޗ̈������
						�|�C���^�ł��B

	IN  pStripContext	StripHead �𐶐����邽�߂̌��ɂȂ�����i�[����
						KMSTRIPCONTEXT �\���̂ւ̃|�C���^���w�肵�܂��B

	IN  nVertexType		�g�p���钸�_�̎�ނɂ���āApStripHead �ɏ������ޓ��e���قȂ邽�߁A
						KMSTRIPCONTEXT ���g�p���Đ������� KMSTRIPHEAD�̌�ɑ���
						���_�̃^�C�v���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmGenerateStripHead(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext,
		IN  KMVERTEXTYPE		nVertexType
	);

/*++
kmGenerateStripHeadxx

proto type:
	KMSTATUS KMAPI
	kmGenerateStripHeadxx(
	        OUT PKMSTRIPHEAD        pStripHead,
	        IN  PKMSTRIPCONTEXT     pStripContext
		);

Description:
	xx �� 00 - 17 �̔C�ӂ̐��l�Œ��_�^�C�v�������܂��B
	�������钸�_�^�C�v�ɓ������� KMSTRIPHEAD �����֐��Q�ł��B

	�e�֐��� pStripContext �̓��e������ xx ������ ���_�^�C�v�ɂ�����
	KMSTRIPHEAD ���쐬�� pStripHead �������̈�ɏ������݂܂��B

Arguments:
	OUT pStripHead		������� KMSTRIPHEAD���������ޗ̈������
						�|�C���^�ł��B

	IN  pStripContext	StripHead �𐶐����邽�߂̌��ɂȂ�����i�[����
						KMSTRIPCONTEXT �\���̂ւ̃|�C���^���w�肵�܂��B

Result:
	KMSTATUS_SUCCESS		����

--*/

KMSTATUS KMAPI
kmGenerateStripHead00(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead01(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead02(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead03(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead04(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead05(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead06(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead07(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead08(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead09(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead10(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead11(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead12(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead13(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead14(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead15(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead16(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

KMSTATUS KMAPI
kmGenerateStripHead17(
        OUT PKMSTRIPHEAD        pStripHead,
        IN  PKMSTRIPCONTEXT     pStripContext
	);

/*++
kmInitStripContext

proto type:
	KMSTATUS KMAPI
	kmInitStripContext(
			IN  KMDWORD		dwIndex,
			OUT PKMVOID		pStripContext
		);

Description:
	�T�^�I�� KMSTRIPCONTEXT �𐶐����ApStripContext�������̈��
	�������݂܂��B

Arguments:
	IN  dwIndex			Index �ł��B
	OUT pStripContext	�󂯎��̈�ւ̃|�C���^�ł��B

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmInitStripContext(
		IN  KMDWORD		dwIndex,
		OUT PKMVOID		pStripContext
	);

/*++
kmRegisterStripContext

proto type:
	KMSTATUS KMAPI
	kmRegisterStripContext(
			IN  KMDWORD				dwIndex,
			IN  PKMSTRIPCONTEXT     pStripContext
		);

Description:
	�悭�g�p���邨�C�ɓ���� STRIPCONTEXT �\���̂�
	��Ŏg�p���邽�߂ɃV�X�e���Ɉ�U�o�^���Ă����֐��ł��B

Arguments:
	IN  dwIndex				����������̈�� index
	IN  pStripContext		

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmRegisterStripContext(
		IN  KMDWORD				dwIndex,
		IN  PKMSTRIPCONTEXT     pStripContext
	);

/*++
kmStartStrip

proto type:
	KMSTATUS KMAPI
	kmStartStrip(
			IN  PKMVERTEXBUFFDESC   pVertexBuffDesc,
			IN  PKMSTRIPHEAD        pStripHead
		);

Description:

Arguments:
	IN  pVertexBuffDesc		�f�[�^��o�^���钸�_�f�[�^���X�g�̏��������A
							PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ�
							�|�C���^�ł��B

	IN  pStripHead			���_���X�g�̐擪�ɂȂ� KMSTRIPHEAD �\���̂ւ�
							�|�C���^�ł��B

Result:
	KMSTATUS_SUCCESS		����

--*/
#if !defined(_KM_USE_VERTEX_MACRO_)
KMSTATUS KMAPI
kmStartStrip(
		IN  PKMVERTEXBUFFDESC   pVertexBuffDesc,
		IN  PKMSTRIPHEAD        pStripHead
	);
#endif


/*++
kmEndStrip

proto type:

Description:

Arguments:
	IN  pVertexBuffDesc		�f�[�^��o�^���钸�_�f�[�^���X�g�̏��������A
							PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ�
							�|�C���^�ł��B

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmEndStrip(
		IN  PKMVERTEXBUFFDESC   pVertexBuffDesc
	);

/*++
kmSetVertex

proto type:
	KMSTATUS
	kmSetVertex(
			PKMVERTEXBUFFDESC pBufferDesc,
			PVOID pVertex,
			KMVERTEXTYPE VertexType,
			KMINT32 StructSize
		);

Description:
	pVertex���w�����_�f�[�^���A�V�X�e���ɓo�^�ς݂̃����_�����p�����[�^�� ListType �Ŏw�肵�����_�f�[�^���X�g�֏������݂܂��B
	�X�g���b�v�̍Ō�ƂȂ钸�_�f�[�^��Parameter Control Word ��KM_VERTEXPARAM_ENDOFSTRIP �łȂ������Ƃ��̓���͕ۏ؂��܂���B

	���ӁF	�����ŏ������ޒ��_�p�����[�^�̌`���ƁA���̑O��kmSetVertexRenderState�Őݒ肵���O���[�o���p�����[�^�̌`����
			�g�ݍ��킹���������Ȃ��ꍇ�̓���͕ۏ؂��܂���B

	<�{�֐��͍�������v������邽��Inline�W�J�����}�N���Ƃ��Ē�`����܂��B>

	�}�N�����g�p����ꍇ�ɂ́A�ȉ��̂悤�ɐݒ肵�Ă��������B

		#define _KM_USE_VERTEX_MACRO_
		#include <kamui.h>
		#include <kamuix.h> 

Arguments:
	IN	pBufferDesc		PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^�ł��B
	IN	pVertex			���_�f�[�^�\���̂ւ̃|�C���^�ł��B
	IN	VertexType		���_�f�[�^�̃f�[�^�^�C�v�������܂��B���L�̂����ꂩ���w�肵�܂��B
						KM_VERTEXTYPE_00			// ���_�f�[�^ Type 0
						KM_VERTEXTYPE_01			// ���_�f�[�^ Type 1
						KM_VERTEXTYPE_02			// ���_�f�[�^ Type 2
						KM_VERTEXTYPE_03			// ���_�f�[�^ Type 3
						KM_VERTEXTYPE_04			// ���_�f�[�^ Type 4
						KM_VERTEXTYPE_05			// ���_�f�[�^ Type 5
						KM_VERTEXTYPE_06			// ���_�f�[�^ Type 6
						KM_VERTEXTYPE_07			// ���_�f�[�^ Type 7
						KM_VERTEXTYPE_08			// ���_�f�[�^ Type 8
						KM_VERTEXTYPE_09			// ���_�f�[�^ Type 9
						KM_VERTEXTYPE_10			// ���_�f�[�^ Type 10
						KM_VERTEXTYPE_11			// ���_�f�[�^ Type 11
						KM_VERTEXTYPE_12			// ���_�f�[�^ Type 12
						KM_VERTEXTYPE_13			// ���_�f�[�^ Type 13
						KM_VERTEXTYPE_14			// ���_�f�[�^ Type 14
						KM_VERTEXTYPE_15			// ���_�f�[�^ Type 15
						KM_VERTEXTYPE_16			// ���_�f�[�^ Type 16
						KM_VERTEXTYPE_17			// ���_�f�[�^ Type 17

	IN	StructSize		���_�f�[�^�̃f�[�^�^�C�v�T�C�Y�������܂��B���_�f�[�^�Ɏg�p����^�C�v�ɍ��킹�āA
						sizeof(KMVERTEX_01)�̗l�Ɏw�肵�Ă��������B

Result:
	KMSTATUS_SUCCESS			���_�f�[�^�������ݐ���
	KMSTATUS_NOT_ENOUGH_MEMORY	���_�f�[�^���X�g�̗e�ʂ�����Ȃ�

--*/
#if !defined(_KM_USE_VERTEX_MACRO_)
KMSTATUS KMAPI
kmSetVertex(
		IN	PKMVERTEXBUFFDESC pBufferDesc,
		IN	PVOID pVertex,
		IN	KMVERTEXTYPE VertexType,
		IN	KMINT32 StructSize
	);
#endif

/*++
kmSetUserClipping

proto type:
	KMSTATUS KMAPI
	kmSetUserClipping(
			IN  PKMVERTEXBUFFDESC   pVertexBuffDesc,
			IN  KMUSERCLIPMODE      nPrevUserClipMode,
			IN  KMLISTTYPE          nListType,
			IN  PKMRECT             pRect
		);

Description:
	IN  pVertexBuffDesc		�f�[�^��o�^���钸�_�f�[�^���X�g�̏��������A
							PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ�
							�|�C���^�ł��B
	IN  nPrevUserClipMode	
	IN  nListType			
	IN  pRect				

Arguments:

Result:
	KMSTATUS_SUCCESS		����
--*/
KMSTATUS KMAPI
kmSetUserClipping(
		IN  PKMVERTEXBUFFDESC   pVertexBuffDesc,
		IN  KMUSERCLIPMODE      nPrevUserClipMode,
		IN  KMLISTTYPE          nListType,
		IN  PKMRECT             pRect
	);

/*++
kmSetStripHead

proto type:
	KMSTATUS KMAPI
	kmSetStripHead(
			IN  PKMVERTEXBUFFDESC   pVertexBuffDesc,
			IN  PKMSTRIPHEAD        pStripHead
		);

Description:

Arguments:
	IN  pVertexBuffDesc		�f�[�^��o�^���钸�_�f�[�^���X�g�̏��������A
							PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ�
							�|�C���^�ł��B
	IN  pStripHead

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmSetStripHead(
		IN  PKMVERTEXBUFFDESC   pVertexBuffDesc,
		IN  PKMSTRIPHEAD        pStripHead
	);

/*++
kmChangeStripXxxx

proto type:
	KMSTATUS KMAPI
	kmChangeStripXxxx(
			IN OUT	PKMSTRIPHEAD	pStripHead,
			IN		KMXXXXXX		xXxx
		);

	KMSTATUS KMAPI
	kmChangeStripXxxx(
			IN OUT	PKMSTRIPHEAD	pStripHead,
			IN		KMINT32			nParam,
			IN		KMBLENDINGMODE	xXxxx
		);

Description:
	kmGenerateStripHead �����g�p���Đ��������AKMSTRIPHEAD �\���̂̓��e��
	�ꕔ����������֐��Q�ł��B

Arguments:
	IN OUT	pStripHead	����������ΏۂƂȂ� KMSTRIPHEAD �\���̂ւ̃|�C���^
	IN		nParam		2 volume �Ɋ֌W����p�����[�^������������ꍇ�ɂ́A
						�ǂ���̃p�����[�^������������̂��𖾎�����K�v������B
	IN		xXxxx		�ύX����p�����[�^

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmChangeStripListType(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMLISTTYPE		nListType
	);
KMSTATUS KMAPI
kmChangeStripUserClipMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMUSERCLIPMODE	nUserClipMode
	);
KMSTATUS KMAPI
kmChangeStripShadowMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMSHADOWMODE	nShadowMode
	);
KMSTATUS KMAPI
kmChangeStripIntensityMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMCOLORTYPE		nIntensityMode
	);
KMSTATUS KMAPI
kmChangeStripOffset(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMBOOLEAN		bOffset
	);
KMSTATUS KMAPI
kmChangeStripGouraud(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMBOOLEAN		bGouraud
	);
KMSTATUS KMAPI
kmChangeStripDepthCompareMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMDEPTHMODE		nDepthCompareMode
	);
KMSTATUS KMAPI
kmChangeStripModifierInstruction(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMDWORD			dwModifierInstruction
	);
KMSTATUS KMAPI
kmChangeStripCullingMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMCULLINGMODE	nCullingMode
	);
KMSTATUS KMAPI
kmChangeStripZWriteDisable(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMBOOLEAN		bZWriteDisable
	);
KMSTATUS KMAPI
kmChangeStripDCalcControl(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMBOOLEAN		bDCalcControl
	);
KMSTATUS KMAPI
kmChangeStripBlendingMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMBLENDINGMODE	nSRCBlendingMode,
		IN		KMBLENDINGMODE	nDSTBlendingMode
	);
KMSTATUS KMAPI
kmChangeStripSRCSelect(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMBOOLEAN		bSRCSelect
	);
KMSTATUS KMAPI
kmChangeStripDSTSelect(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMBOOLEAN		bDSTSelect
	);
KMSTATUS KMAPI
kmChangeStripFogMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMFOGMODE		nFogMode
	);
KMSTATUS KMAPI
kmChangeStripColorClamp(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMBOOLEAN		bColorClamp
	);
KMSTATUS KMAPI
kmChangeStripUseAlpha(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMBOOLEAN		bUseAlpha
	);
KMSTATUS KMAPI
kmChangeStripIgnoreTextureAlpha(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMBOOLEAN		bIgnoreTextureAlpha
	);
KMSTATUS KMAPI
kmChangeStripFlipUV(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMFLIPMODE		nFlipUV
	);
KMSTATUS KMAPI
kmChangeStripClampUV(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMCLAMPMODE		nClampUV
	);
KMSTATUS KMAPI
kmChangeStripFilterMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMFILTERMODE	nFilterMode
	);
KMSTATUS KMAPI
kmChangeStripSuperSampleMode(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMBOOLEAN		bSuperSampleMode
	);
KMSTATUS KMAPI
kmChangeStripMipmapAdjust(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMDWORD			dwMipmapAdjust
	);
KMSTATUS KMAPI
kmChangeStripTextureShadingMode(
		IN OUT	PKMSTRIPHEAD			pStripHead,
		IN		KMINT32					nParam,
		IN		KMTEXTURESHADINGMODE	nTextureShadingMode
	);
KMSTATUS KMAPI
kmChangeStripPaletteBank(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		KMDWORD			dwPaletteBank
	);
KMSTATUS KMAPI
kmChangeStripTextureSurface(
		IN OUT	PKMSTRIPHEAD	pStripHead,
        IN      KMINT32         nParam,
		IN		PKMSURFACEDESC	pTextureSurfaceDesc
	);
KMSTATUS KMAPI
kmChangeStripTextureAddress(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		PKMSURFACEDESC	pTextureSurfaceDesc
	);
KMSTATUS KMAPI
kmChangeStripFaceColor(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMINT32			nParam,
		IN		PKMFLOATCOLOR	pFaceColor
	);
KMSTATUS KMAPI
kmChangeStripFaceOffsetColor(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		PKMFLOATCOLOR	pFaceOffsetColor
	);
KMSTATUS KMAPI
kmChangeStripSpriteBaseColor(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMPACKEDARGB	dwBaseColor
	);
KMSTATUS KMAPI
kmChangeStripSpriteOffsetColor(
		IN OUT	PKMSTRIPHEAD	pStripHead,
		IN		KMPACKEDARGB	dwOffsetColor
	);

/*++
kmChangeContextXxxxx

proto type:

	KMSTATUS KMAPI
	kmChangeContextXxxx(
			IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
			IN		KMXXXX				xXxxxx
		);

	KMSTATUS KMAPI
	kmChangeContextXxxxx(
			IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
			IN		KMINT32				nParam,
			IN		KMXXXX				xXxxxx
		);

Description:
	kmSetStripHead ���g�p���āA�ꎞ�V�X�e���ɓo�^�����A
	KMSTRIPHEAD �\���̂�����������֐��Q�ł��B

Arguments:
	IN OUT	pVertexBuffDesc		�f�[�^��ύX���钸�_�f�[�^���X�g�̏��������A
								PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ�
								�|�C���^�ł��B

	IN		nParam				2�{�����[���Ɋ֌W����֐��ł͕K�v�ł��B
								0 / 1 �����Ă��������B

	IN		xXxxxx				�ύX����p�����[�^

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmChangeContextListType(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMLISTTYPE			nListType
	);

KMSTATUS KMAPI
kmChangeContextUserClipMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMUSERCLIPMODE		nUserClipMode
	);

KMSTATUS KMAPI
kmChangeContextShadowMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMSHADOWMODE		nShadowMode
	);

KMSTATUS KMAPI
kmChangeContextIntensityMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMCOLORTYPE			nIntensityMode
	);

KMSTATUS KMAPI
kmChangeContextOffset(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMBOOLEAN			bOffset
	);

KMSTATUS KMAPI
kmChangeContextGouraud(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMBOOLEAN			bGouraud
	);

KMSTATUS KMAPI
kmChangeContextDepthCompareMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMDEPTHMODE			nDepthCompareMode
	);

KMSTATUS KMAPI
kmChangeContextModifierInstruction(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMDWORD				dwModifierInstruction
	);

KMSTATUS KMAPI
kmChangeContextCullingMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMCULLINGMODE		nCullingMode
	);

KMSTATUS KMAPI
kmChangeContextZWriteDisable(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMBOOLEAN			bZWriteDisable
	);

KMSTATUS KMAPI
kmChangeContextDCalcControl(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMBOOLEAN			bDCalcControl
	);

KMSTATUS KMAPI
kmChangeContextBlendingMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMBLENDINGMODE		nSRCBlendingMode,
		IN		KMBLENDINGMODE		nDSTBlendingMode
	);

KMSTATUS KMAPI
kmChangeContextSRCSelect(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMBOOLEAN			bSRCSelect
	);

KMSTATUS KMAPI
kmChangeContextDSTSelect(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMBOOLEAN			bDSTSelect
	);

KMSTATUS KMAPI
kmChangeContextFogMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMFOGMODE			nFogMode
	);

KMSTATUS KMAPI
kmChangeContextColorClamp(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMBOOLEAN			bColorClamp
	);

KMSTATUS KMAPI
kmChangeContextUseAlpha(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMBOOLEAN			bUseAlpha
	);

KMSTATUS KMAPI
kmChangeContextIgnoreTextureAlpha(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMBOOLEAN			bIgnoreTextureAlpha
	);

KMSTATUS KMAPI
kmChangeContextFlipUV(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMFLIPMODE			nFlipUV
	);

KMSTATUS KMAPI
kmChangeContextClampUV(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMCLAMPMODE			nClampUV
	);

KMSTATUS KMAPI
kmChangeContextFilterMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMFILTERMODE		nFilterMode
	);

KMSTATUS KMAPI
kmChangeContextSuperSampleMode(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMBOOLEAN			bSuperSampleMode
	);

KMSTATUS KMAPI
kmChangeContextMipmapAdjust(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMDWORD				dwMipmapAdjust
	);

KMSTATUS KMAPI
kmChangeContextTextureShadingMode(
		IN OUT	PKMVERTEXBUFFDESC		pVertexBuffDesc,
		IN		KMINT32					nParam,
		IN		KMTEXTURESHADINGMODE	nTextureShadingMode
	);

KMSTATUS KMAPI
kmChangeContextPaletteBank(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		KMDWORD				dwPaletteBank
	);

KMSTATUS KMAPI
kmChangeContextTextureSurface(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
        IN      KMINT32				nParam,
		IN		PKMSURFACEDESC		pTextureSurfaceDesc
	);

KMSTATUS KMAPI
kmChangeContextTextureAddress(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		PKMSURFACEDESC		pTextureSurfaceDesc
	);

KMSTATUS KMAPI
kmChangeContextFaceColor(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMINT32				nParam,
		IN		PKMFLOATCOLOR		pFaceColor
	);

KMSTATUS KMAPI
kmChangeContextFaceOffsetColor(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		PKMFLOATCOLOR		pFaceOffsetColor
	);

KMSTATUS KMAPI
kmChangeContextSpriteBaseColor(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMPACKEDARGB		dwBaseColor
	);

KMSTATUS KMAPI
kmChangeContextSpriteOffsetColor(
		IN OUT	PKMVERTEXBUFFDESC	pVertexBuffDesc,
		IN		KMPACKEDARGB		dwOffsetColor
	);

/*----------------------------------------*/
/* KAMUI1 Legacy API                      */
/* -----------------                      */
/* sorry following functions too slow!!   */
/* and KMVERTEXCONTEXT was huge....       */
/* we only left backward compatibility    */
/*----------------------------------------*/
/*++
kmProcessVertexRenderState

proto type:
	KMSTATUS
	kmProcessVertexRenderState(
				PKMVERTEXCONTEXT pVertexContext
			);

Description:
	���_(�X�g���b�v)���ƂɗL���ƂȂ郌���_�����O�E�p�����[�^��ݒ肵�܂�
	(pVertexContext�̐ݒ�l���V�X�e���ɓo�^���邽�߂̑O�������s���܂�)�B

	�{�֐���pVertexContext�ɐݒ肳�ꂽ�l�����ƂɈȉ��̒l�𐶐����܂��B
			Global Parameter
			Combined ISP/TSP
			Instruction Word
			TSP Control Word
			Texture Control Bits

	�{�֐�������������L�f�[�^�́AKMVERTEXCONTEXT���̈ȉ��Ɏ��������o�ɕۑ����܂��B
			pVertexContext->GLOBALPARAMBUFFER
			pVertexContext->ISPPARAMBUFFER
			pVertexContext->TSPPARAMBUFFER
			pVertexContext->TexturePARAMBUFFER

	�{�֐��ɂ��A�O�������s���� pVertexContext �̏�L�����o�������_�����O�Ɏg�p����
	�p�����[�^�Ƃ��āA�V�X�e���ɓo�^���邽�߂ɂ́AkmSetVertexRenderState���Ăяo�����ƕK�v������܂��B

	VERTEXCONTEXT���ŏ��Ɏg�p���鎞�ɂ́AVERTEXCONTEXT�̂��ׂẴ����o�̒l���w��(������)����
	�K�v������܂��B

	���F
		pVertexContext->RenderState �ɂ��ׂẴt���O��ݒ肵�A���ׂẴp�����[�^���`���Ă��������B
		����`�̃r�b�g���������ꍇ�̓���͕ۏ؂��܂���B

Arguments:
	IN	pVertexContext		�R���e�L�X�g�ւ̃|�C���^��ݒ肵�܂��B

Result:
	KMSTATUS_SUCCESS		�ݒ萬��
	KMSTATUS_INVALIDSETTING	������Ă��Ȃ����[�h�ݒ�

--*/
KMSTATUS KMAPI
kmProcessVertexRenderState(
		IN	PKMVERTEXCONTEXT pVertexContext
	);

/*++
kmSetVertexRenderState

proto type:

	KMSTATUS
	kmSetVertexRenderState (
        	PKMVERTEXBUFFDESC   pVertexBuffDesc,
			PKMVERTEXCONTEXT 	pVertexContext
		);

Description:
	kmProcessVertexRenderState�ŏ������� pVertexContext ���̈ȉ��̃����o�y�ъ֘A����l��
	�����_�����O�Ɏg�p����p�����[�^�Ƃ��ăV�X�e���ɓo�^���܂��B

			pVertexContext->GLOBALPARAMBUFFER
			pVertexContext->ISPPARAMBUFFER
			pVertexContext->TSPPARAMBUFFER
			pVertexContext->TexturePARAMBUFFER

	�{�֐��̌Ăяo���Őݒ肵���p�����[�^�� �{�֐��̌�ŌĂяo����� kmStartVertexStrip 
	�ȍ~�̒��_(Strip)�o�^�ŗL���ƂȂ�܂��B


Arguments:
	OUT	pVertexBuffDesc		KMVERTEXBUFFDESC �\���̂ւ̃|�C���^��ݒ肵�܂��B
	IN	pVertexContext		KMVERTEXCONTEXT �\���̂ւ̃|�C���^��ݒ肵�܂��B

Result:
	KMSTATUS_SUCCESS		�����_�����O�p�����[�^�o�^����

--*/
KMSTATUS KMAPI
kmSetVertexRenderState (
        OUT	PKMVERTEXBUFFDESC   pVertexBuffDesc,
		IN	PKMVERTEXCONTEXT 	pVertexContext
	);

/*++
kmSetModifierRenderState

proto type:
	KMSTATUS
	kmSetModifierRenderState(
        	PKMVERTEXBUFFDESC   pVertexBuffDesc,
			PKMVERTEXCONTEXT 	pVertexContext
		);

Description:
	kmProcessVertexRenderState�Őݒ肵��KMVERTEXCONTEXT���̈ȉ��̃����o���A
	 Modifier Volume �̉e�����󂯂� Polygon�́A2 �Ԗڂ̃����_�����O�p�����[�^
	�Ƃ��ăV�X�e���ɓo�^���܂��B

				pVertexContext->TSPPARAMBUFFER
				pVertexContext->TexturePARAMBUFFER

	�ȍ~�� Modifier Volume �̉e�����󂯂� Polygon �̓o�^�ł́A�{�֐��Ŏw�肵��
	KMVERTEXCONTEXT�� 2 �Ԗڂ̃����_�����O�p�����[�^�Ƃ��Ďg�p���܂��B

	KMVERTEXCONTEXT�\���̂̂����ȉ��̃����o�͎Q�Ƃ��܂���(�������܂�)�B
	(kmSetVertexRenderState�Őݒ肵���l���L���ƂȂ�܂�)
	// for Global Parameter
	KMPARAMTYPE			ParamType			// Parameter Type
	KMLISTTYPE			ListType			// List Type
	KMSTRIPLENGTH		StripLength			// Strip Length
	KMUSERCLIPMODE		UserClipMode		// UserClip Mode
	KMCOLORTYPE			ColorType			// Color Type
	KMUVFORMAT			UVFormat			// UV format

	// for ISP/TSP Instruction Word
	KMDEPTHMODE			DepthMode;			// DepthMode�w��
	KMCULLINGMODE		CullingMode;		// Culling Mode
	KMSCREENCORDINATION	ScreenCoordination;	// Screen Coordination
	KMSHADINGMODE		ShadingMode;		// Shading Mode
	KMMODIFIER			SelectModifier;		// Modifier Volume Valiant
	KMBOOLEAN			bZWriteDisable;		// Z Write Disable

	// for ModifierInstruction
	KMDWORD				ModifierInstruction;// ModifierInstruction
	KMFLOAT				fBoundingBoxXmin;	// BoundingBoxXmin(ShadowVolume)
	KMFLOAT				fBoundingBoxYmin;	// BoundingBoxYmin(ShadowVolume)
	KMFLOAT				fBoundingBoxXmax;	// BoundingBoxXmax(ShadowVolume)
	KMFLOAT				fBoundingBoxYmax;	// BoundingBoxYmax(ShadowVolume)

Arguments:
	IN	OUT	pVertexBuffDesc		pVertexContext �����p�����[�^��o�^�o�^����
								KMVERTEXBUFFDESC �\���̂ւ̃|�C���^.
								���炩���� kmSetSystemConfiguration �ɂ�
								����������Ă���K�v������܂��B

	IN		pVertexContext		KMVERTEXCONTEXT �\���̂ւ̃|�C���^��ݒ肵�܂��B

Result:
	KMSTATUS_SUCCESS			���f�B�t�@�C�A�̉e�����󂯂郌���_�����O�p�����[�^
								�o�^����

--*/

KMSTATUS KMAPI
kmSetModifierRenderState(
        IN	OUT	PKMVERTEXBUFFDESC   pVertexBuffDesc,
		IN		PKMVERTEXCONTEXT 	pVertexContext
	);


/*++
kmStartVertexStrip

proto type:
	KMSTATUS
	kmStartVertexStrip( 
			PKMVERTEXBUFFDESC pBufferDesc
		);

Description:
	�_�ЂɁA���_�f�[�^�X�g���b�v�̓o�^���J�n���邱�Ƃ�ʒm���܂��B
	�ȉ��̊֐��̌Ăяo���ŃV�X�e���ɓo�^����

		kmSetVertexRenderState
		kmSetModifierRenderState

	�����_�����O�p�����[�^���A5��̒��_�f�[�^���X�g�̂����ꂩ�֏������݂܂��B
	�������ޒ��_�f�[�^���X�g�́A KMVERTEXCONTEXT��
	ListType�����o���猈�肳��܂��B

���ӁF�����ŏ������񂾃����_�����O�p�����[�^�̏��ƁA����ɑ���kmSetVertex�ő���
	  ���_�p�����[�^�̌`���̑g�ݍ��킹���������Ȃ��ꍇ�̓���͕ۏ؂���܂���B

	<�{�֐��͍�������v������邽��Inline�W�J�����}�N���Ƃ��Ē�`����܂��B>

	�}�N�����g�p����ꍇ�ɂ́A�ȉ��̂悤�ɐݒ肵�Ă��������B

		#define _KM_USE_VERTEX_MACRO_
		#include <kamui.h>
		#include <kamuix.h> 

Arguments:
	IN	pBufferDesc				PKMVERTEXBUFFDESC�^�́AVertex Buffer Descriptor�ւ̃|�C���^�ł��B
								�f�[�^��o�^���钸�_�f�[�^���X�g�̏��������B

Result:
	KMSTATUS_SUCCESS			�����_�����O�p�����[�^ �������ݐ���
	KMSTATUS_NOT_ENOUGH_MEMORY	���_�f�[�^���X�g�̗e�ʂ�����Ȃ�

--*/
#if !defined(_KM_USE_VERTEX_MACRO_)
KMSTATUS KMAPI
kmStartVertexStrip( 
		IN	PKMVERTEXBUFFDESC pBufferDesc
	);
#endif


/*++
kmEndVertexStrip

proto type:
	KMSTATUS KMAPI
	kmEndVertexStrip(
			IN  PKMVERTEXBUFFDESC   pVertexBuffDesc
		);
	
Description:
	
Arguments:
	IN	pVertexBuffDesc		

Result:
	KMSTATUS_SUCCESS		����

--*/
KMSTATUS KMAPI
kmEndVertexStrip(
		IN  PKMVERTEXBUFFDESC   pVertexBuffDesc
	);
#endif