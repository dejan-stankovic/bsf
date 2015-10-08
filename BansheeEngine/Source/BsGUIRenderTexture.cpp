#include "BsGUIRenderTexture.h"
#include "BsCGUIWidget.h"
#include "BsGUISkin.h"
#include "BsGUIManager.h"
#include "BsRenderTexture.h"
#include "BsSpriteTexture.h"

namespace BansheeEngine
{
	const String& GUIRenderTexture::getGUITypeName()
	{
		static String name = "RenderTexture";
		return name;
	}

	GUIRenderTexture::GUIRenderTexture(const String& styleName, const RenderTexturePtr& texture, const GUIDimensions& dimensions)
		:GUITexture(styleName, HSpriteTexture(), GUIImageScaleMode::StretchToFit, false, dimensions)
	{
		setRenderTexture(texture);
	}

	GUIRenderTexture::~GUIRenderTexture()
	{
		if (mSourceTexture != nullptr)
			GUIManager::instance().setInputBridge(mSourceTexture.get(), nullptr);
	}

	GUIRenderTexture* GUIRenderTexture::create(const RenderTexturePtr& texture, const String& styleName)
	{
		return new (bs_alloc<GUIRenderTexture>()) GUIRenderTexture(getStyleName<GUIRenderTexture>(styleName), texture, GUIDimensions::create());
	}

	GUIRenderTexture* GUIRenderTexture::create(const RenderTexturePtr& texture, const GUIOptions& options, const String& styleName)
	{
		return new (bs_alloc<GUIRenderTexture>()) GUIRenderTexture(getStyleName<GUIRenderTexture>(styleName), texture, GUIDimensions::create(options));
	}

	void GUIRenderTexture::setRenderTexture(const RenderTexturePtr& texture)
	{
		if (mSourceTexture != nullptr)
			GUIManager::instance().setInputBridge(mSourceTexture.get(), nullptr);

		mSourceTexture = texture;

		if (mSourceTexture != nullptr)
		{
			if (mSourceTexture->getProperties().requiresTextureFlipping())
			{
				mDesc.uvOffset = Vector2(0.0f, 1.0f);
				mDesc.uvScale = Vector2(1.0f, -1.0f);
			}

			setTexture(SpriteTexture::create(texture->getBindableColorTexture()));

			GUIManager::instance().setInputBridge(mSourceTexture.get(), this);
		}
		else
		{
			setTexture(SpriteTexture::create(HTexture()));
		}

		_markLayoutAsDirty();
	}

	void GUIRenderTexture::updateRenderElementsInternal()
	{		
		if(mActiveTexture != nullptr && mActiveTexture.isLoaded())
		{
			mDesc.texture = mActiveTexture.getInternalPtr();
		}

		mDesc.width = mLayoutData.area.width;
		mDesc.height = mLayoutData.area.height;
		mDesc.transparent = false;
		mDesc.color = getTint();

		mImageSprite->update(mDesc, (UINT64)_getParentWidget());

		GUIElement::updateRenderElementsInternal();
	}
}