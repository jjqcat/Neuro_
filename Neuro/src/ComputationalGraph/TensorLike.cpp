﻿#include "ComputationalGraph/TensorLike.h"
#include "ComputationalGraph/NameScope.h"
#include "ComputationalGraph/Graph.h"

namespace Neuro
{
    //////////////////////////////////////////////////////////////////////////
    TensorLike::TensorLike(const string& name)
    {
        m_Name = NameScope::Name() + name;
        m_Graph = Graph::Default();
        m_Output.Name(m_Name + "/output");
        m_OutputGrad.Name(m_Name + "/output[grad]");
    }
}
