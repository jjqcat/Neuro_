﻿#include <iomanip>
#include <sstream>

#include "Models/ModelBase.h"
#include "Layers/LayerBase.h"

namespace Neuro
{
    //////////////////////////////////////////////////////////////////////////
    string ModelBase::Summary() const
    {
        stringstream ss;
        int totalParams = 0;
        ss << "_________________________________________________________________\n";
        ss << "Layer                        Output Shape              Param #   \n";
        ss << "=================================================================\n";

        for (auto layer : GetLayers())
        {
            totalParams += layer->GetParamsNum();
            ss << left << setw(29) << (layer->Name() + "(" + layer->ClassName() + ")");
            ss << setw(26) << layer->OutputShape().ToString();
            ss << setw(13) << layer->GetParamsNum() << "\n";
            if (layer->InputLayers().size() > 1)
            {
                for (int i = 0; i < (int)layer->InputLayers().size(); ++i)
                    ss << layer->InputLayers()[i]->Name() << "\n";
            }
            ss << "_________________________________________________________________\n";
        }

        ss << "Total params: " << totalParams << "\n";
        return ss.str();
    }

    //////////////////////////////////////////////////////////////////////////
    string ModelBase::TrainSummary() const
    {
        stringstream ss;
        int totalParams = 0;
        ss << "_____________________________________________________________________________\n";
        ss << "Layer                        FeedFwd     BackProp    ActFeedFwd  ActBackProp \n";
        ss << "=============================================================================\n";

        for (auto layer : GetLayers())
        {
            ss << left << setw(29) << (layer->Name() + "(" + layer->ClassName() + ")");
            ss << setw(12) << (to_string(layer->FeedForwardTime()/1000.f) + "s");
            ss << setw(12) << (to_string(layer->BackPropTime()/1000.f) + "s");
            ss << setw(12) << (to_string(layer->ActivationTime()/1000.f) + "s");
            ss << setw(12) << (to_string(layer->ActivationBackPropTime()/1000.f) + "s") << "\n";
            ss << "_____________________________________________________________________________\n";
        }

        return ss.str();
    }

    //////////////////////////////////////////////////////////////////////////
	const LayerBase* ModelBase::GetLayer(const string& name) const
	{
		for (auto layer : GetLayers())
		{
			if (layer->Name() == name)
				return layer;
		}
		return nullptr;
	}

	//////////////////////////////////////////////////////////////////////////
	vector<ParametersAndGradients> ModelBase::GetParametersAndGradients()
	{
		vector<ParametersAndGradients> result;

		for(auto layer : GetLayers())
		{
			layer->GetParametersAndGradients(result);
		}

		return result;
	}

}
