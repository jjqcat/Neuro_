#include "ComputationalGraph/Operations/DropoutOp.h"

namespace Neuro
{
    //////////////////////////////////////////////////////////////////////////
    DropoutOp::DropoutOp(TensorLike* x, float prob, TensorLike* training)
        : Operation({ x, training }, "dropout"), m_Prob(prob)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    void DropoutOp::ComputeInternal()
    {
        auto& x = *m_Inputs[0];
        bool training = (*m_Inputs[1])(0) != 0;

        m_Output.Resize(m_Inputs[0]->GetShape());
        if (training)
        {
            m_Mask.Resize(m_Inputs[0]->GetShape());
            m_Inputs[0]->Dropout(m_Prob, m_Mask, m_Output);
        }
        else
        {
            m_Inputs[0]->CopyTo(m_Output);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    void DropoutOp::ComputeGradientInternal(const Tensor& grad)
    {
        grad.DropoutGradient(grad, m_Mask, m_InputsGrads[0]);
    }
}