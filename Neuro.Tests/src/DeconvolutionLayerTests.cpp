#include <memory>

#include "CppUnitTest.h"
#include "Neuro.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Neuro;

namespace NeuroTests
{
    TEST_CLASS(DeconvolutionLayerTests)
    {
        TEST_METHOD(InputGradient_1Batch_Valid)
        {
            Assert::IsTrue(TestTools::VerifyInputGradient(std::unique_ptr<LayerBase>(CreateLayer(2)).get()));
        }

        TEST_METHOD(InputGradient_1Batch_Full)
        {
            Assert::IsTrue(TestTools::VerifyInputGradient(std::unique_ptr<LayerBase>(CreateLayer(3)).get()));
        }

        TEST_METHOD(InputGradient_1Batch_Same)
        {
            Assert::IsTrue(TestTools::VerifyInputGradient(std::unique_ptr<LayerBase>(CreateLayer(0)).get()));
        }

        TEST_METHOD(InputGradient_3Batches_Valid)
        {
            Assert::IsTrue(TestTools::VerifyInputGradient(std::unique_ptr<LayerBase>(CreateLayer(2)).get(), 3));
        }

        TEST_METHOD(ParametersGradient_1Batch_Valid)
        {
            Assert::IsTrue(TestTools::VerifyParametersGradient(std::unique_ptr<LayerBase>(CreateLayer(2)).get()));
        }

        TEST_METHOD(ParametersGradient_1Batch_Full)
        {
            Assert::IsTrue(TestTools::VerifyParametersGradient(std::unique_ptr<LayerBase>(CreateLayer(3)).get()));
        }

        TEST_METHOD(ParametersGradient_1Batch_Same)
        {
            Assert::IsTrue(TestTools::VerifyParametersGradient(std::unique_ptr<LayerBase>(CreateLayer(0)).get()));
        }

        TEST_METHOD(ParametersGradient_3Batches_Valid)
        {
            Assert::IsTrue(TestTools::VerifyInputGradient(std::unique_ptr<LayerBase>(CreateLayer(2)).get(), 3));
        }

        TEST_METHOD(Train_Stride1_Pad1)
        {
            TestTrain(1, 1);
        }

        TEST_METHOD(Train_Stride1_Pad2)
        {
            TestTrain(1, 2);
        }

        TEST_METHOD(Train_Stride1_Pad0)
        {
            TestTrain(1, 0);
        }

        TEST_METHOD(Train_Stride1_Pad1_Batch2)
        {
            TestTrain(1, 1, 2);
        }

        TEST_METHOD(Train_Stride1_Pad2_Batch2)
        {
            TestTrain(1, 2, 2);
        }

        TEST_METHOD(Train_Stride1_Pad0_Batch2)
        {
            TestTrain(1, 0, 2);
        }

        void TestTrain(int stride, int padding, int batch = 1)
        {
            GlobalRngSeed(101);
            Shape inputShape(4, 4, 3, batch);

            auto model = new Sequential();
            model->AddLayer(new Conv2DTranspose(inputShape, 3, 3, stride, padding));
            auto net = new NeuralNetwork(model, "deconvolution_test", 7);

            Tensor randomKernels(Shape(3, 3, 3, 3));
            randomKernels.FillWithRand();

            Tensor input(inputShape);
            input.FillWithRand();
            Tensor output = input.Conv2DTransposed(randomKernels, 3, stride, padding);

            net->Optimize(new SGD(0.04f), new MeanSquareError());
            net->Fit(input, output, -1, 200, nullptr, nullptr, 1, Track::TrainError);

            const Tensor* predictedOutput = net->Predict(input)[0];

            Assert::IsTrue(net->GetLastTrainError() < 0.001f);
        }

        LayerBase* CreateLayer(int padding)
        {
            auto layer = new Conv2DTranspose(Shape(5, 5, 2), 3, 3, 1, padding);
            layer->Init();
            layer->Kernels().FillWithRand();
            return layer;
        }
    };
}
