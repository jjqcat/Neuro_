#pragma once

#include "Layers/SingleLayer.h"

namespace Neuro
{
    class UpSampling2D : public SingleLayer
    {
    public:
        UpSampling2D(LayerBase* inputLayer, uint32_t scaleFactor, const string& name = "");
        // Make sure to link this layer to input when using this constructor.
        UpSampling2D(uint32_t scaleFactor, const string& name = "");
        // Use this constructor for input layer only!
        UpSampling2D(Shape inputShape, uint32_t scaleFactor, const string& name = "");

    protected:
        UpSampling2D() {}

        virtual LayerBase* GetCloneInstance() const override;
        virtual void OnClone(const LayerBase& source) override;
        virtual void OnLink(LayerBase* layer, bool input) override;
        virtual void FeedForwardInternal(bool training) override;
        virtual void BackPropInternal(const tensor_ptr_vec_t& outputsGradient) override;

    private:
        int m_ScaleFactor;
    };
}
