#include "AutoencoderNetwork.h"
#include "ConvAutoencoderNetwork.h"
#include "ConvNetwork.h"
#include "FlowNetwork.h"
#include "IrisNetwork.h"
#include "MnistConvNetwork.h"
#include "MnistNetwork.h"
#include "GAN.h"
#include "DeepConvGAN.h"
#include "CifarGAN.h"

int main()
{
    {
        
    }

    /*{
        auto in = new Dense(5, 7, new ReLU());

        auto flowIn1 = new Input(Shape(1, 7));
        auto flowIn2 = new Input(Shape(1, 7));

        model->AddLayer(new Flow({ flowIn1, flowIn2 }, { flowIn1, flowIn2 }));
        model->AddLayer(new Dense(1));
    }*/

    //IrisNetwork().Run();
    //ConvNetwork().Run();
    //FlowNetwork().Run();
    //MnistConvNetwork().Run();
    //MnistNetwork().Run();
    //AutoencoderNetwork::Run();
    //ConvAutoencoderNetwork::Run();
    //GAN().Run();
    DeepConvGAN().Run();
    //CifarGAN().Run();

    //Tensor::SetDefaultOpMode(EOpMode::MultiCPU);
    //int inputsNum = 100;

    //auto model = new Sequential("generator");
    //model->AddLayer(new Dense(inputsNum, 128 * 7 * 7, new ReLU())); //0
    //model->AddLayer(new Reshape(Shape(7, 7, 128))); //1
    //model->AddLayer(new UpSampling2D(2)); //2
    //model->AddLayer(new Conv2D(3, 128, 1, Tensor::GetPadding(Same, 3))); //3
    //model->AddLayer((new BatchNormalization())->SetMomentum(0.8f)); //4
    //model->AddLayer(new Activation(new ReLU())); //5
    //model->AddLayer(new UpSampling2D(2)); //6
    //model->AddLayer(new Conv2D(3, 64, 1, Tensor::GetPadding(Same, 3))); //7
    //model->AddLayer((new BatchNormalization())->SetMomentum(0.8f)); //8
    //model->AddLayer(new Activation(new ReLU())); //9
    //model->AddLayer(new Conv2D(3, 1, 1, Tensor::GetPadding(Same, 3), new Tanh())); //10

    //Tensor noise(model->InputShape());
    //noise.FillWithFunc([]() { return Normal::NextSingle(0, 1); });

    //noise.DebugDumpValues("__noise.log");

    //Tensor fakeImages = model->Predict(noise)[0];

    //int i = 0;
    //for (auto param : model->Layer(10)->GetParams())
    //    param->DebugDumpValues(string("__weights") + to_string(i++) + ".log");

    //fakeImages.DebugDumpValues("__fakeImg.log");
    //fakeImages.Map([](float x) { return (0.5f * x + 0.5f) * 255.f; }).Reshaped(Shape(28, 28, 1, -1)).SaveAsImage("__fakeImg.png", false);

    cin.get();

    /*Tensor images1, labels1, images2, labels2, images3, labels3, images4, labels4, images5, labels5;
    LoadCifar10Data("data/data_batch_1.bin", images1, labels1, false, true, -1);
    LoadCifar10Data("data/data_batch_2.bin", images2, labels2, false, true, -1);
    LoadCifar10Data("data/data_batch_3.bin", images3, labels3, false, true, -1);
    LoadCifar10Data("data/data_batch_4.bin", images4, labels4, false, true, -1);
    LoadCifar10Data("data/data_batch_5.bin", images5, labels5, false, true, -1);
    Tensor images(Shape::From(images1.GetShape(), 50000)), labels(Shape::From(labels1.GetShape(), 50000));
    Tensor::Concat(Global, { &images1, &images2, &images3, &images4, &images5 }, images);
    Tensor::Concat(Global, { &labels1, &labels2, &labels3, &labels4, &labels5 }, labels);*/

    /*Tensor::SetDefaultOpMode(GPU);

    Tensor images, labels;
    LoadCifar10Data("data/cifar10_data.bin", images, labels, false);
    images.Map([](float x) { return (x - 127.5f) / 127.5f; }, images);

    auto dModel = new Sequential("discriminator");
    dModel->AddLayer(new Conv2D(Shape(32, 32, 3), 3, 64, 2, Tensor::GetPadding(Same, 3), new LeakyReLU(0.2f)));
    dModel->AddLayer(new Conv2D(3, 128, 2, Tensor::GetPadding(Same, 3), new LeakyReLU(0.2f)));
    dModel->AddLayer(new Conv2D(3, 128, 2, Tensor::GetPadding(Same, 3), new LeakyReLU(0.2f)));
    dModel->AddLayer(new Conv2D(3, 256, 1, Tensor::GetPadding(Same, 3), new LeakyReLU(0.2f)));
    dModel->AddLayer(new Flatten());
    dModel->AddLayer(new Dropout(0.4f));
    dModel->AddLayer(new Dense(1, new Sigmoid()));
    dModel->Optimize(new Adam(0.0002f, 0.5f), new BinaryCrossEntropy());

    auto gModel = new Sequential("generator");
    gModel->AddLayer(new Dense(100, 256*4*4, new LeakyReLU(0.2f)));
    gModel->AddLayer(new Reshape(Shape(4, 4, 256)));
    gModel->AddLayer(new Conv2DTranspose(4, 128, 2, 1, new LeakyReLU(0.2f)));
    gModel->AddLayer(new Conv2DTranspose(4, 128, 2, 1, new LeakyReLU(0.2f)));
    gModel->AddLayer(new Conv2DTranspose(4, 128, 2, 1, new LeakyReLU(0.2f)));
    gModel->AddLayer(new Conv2D(3, 3, 1, Tensor::GetPadding(Same, 3), new Tanh()));
    cout << gModel->Summary();

    auto ganModel = new Sequential("cifar_gan");
    ganModel->AddLayer(gModel);
    ganModel->AddLayer(dModel);
    ganModel->Optimize(new Adam(0.0002f, 0.5f), new BinaryCrossEntropy());

    const uint32_t BATCH_SIZE = 128;
    const uint32_t EPOCHS = 200;
    const uint32_t BATCHES_PER_EPOCH = images.Batch() / BATCH_SIZE;

    Tensor real(Shape::From(dModel->OutputShape(), BATCH_SIZE)); real.FillWithValue(1.f);
    Tensor fake(Shape::From(dModel->OutputShape(), BATCH_SIZE)); fake.FillWithValue(0.f);
    Tensor noise(Shape::From(gModel->InputShape(), BATCH_SIZE));*/

    //for (uint32_t i = 0; i < EPOCHS; ++i)
    //{
    //    Tensor fakeImages(Shape::From(dModel->InputShape(), BATCH_SIZE)); fakeImages.FillWithFunc([]() { return Uniform::NextSingle(-1, 1); });
    //    Tensor realImages = images.GetRandomBatches(BATCH_SIZE);

    //    auto realTrainData = dModel->TrainOnBatch(realImages, real);
    //    auto fakeTrainData = dModel->TrainOnBatch(fakeImages, fake);

    //    float dLoss = (get<0>(realTrainData) + get<0>(fakeTrainData)) * 0.5f;

    //    cout << ">" << i+1 << setprecision(4) << fixed << " loss=" << dLoss << " real=" << round(get<1>(realTrainData)*100) << "% fake=" << round(get<1>(fakeTrainData)*100) << "%" << endl;
    //}

    //for (uint32_t e = 1; e <= EPOCHS; ++e)
    //{
    //    cout << "Epoch " << e << endl;

    //    float totalGanLoss = 0.f;
    //    float totalDiscriminatorLoss = 0.f;

    //    //Tqdm progress(BATCHES_NUM);
    //    for (uint32_t i = 1; i <= BATCHES_PER_EPOCH; ++i)
    //    {
    //        noise.FillWithFunc([]() { return Normal::NextSingle(0, 1); });
    //        Tensor fakeImages = gModel->Predict(noise)[0];
    //        Tensor realImages = images.GetRandomBatches(BATCH_SIZE);

    //        if (i % 50 == 0)
    //        {
    //            fakeImages.Map([](float x) { return x * 127.5f + 127.5f; }).SaveAsImage("fake_images.png", false);
    //            realImages.Map([](float x) { return x * 127.5f + 127.5f; }).SaveAsImage("real_images.png", false);
    //        }

    //        dModel->SetTrainable(true);
    //        auto realTrainRes = dModel->TrainOnBatch(realImages, real);
    //        auto fakeTrainRes = dModel->TrainOnBatch(fakeImages, fake);
    //        dModel->SetTrainable(false);
    //        auto ganTrainRes = ganModel->TrainOnBatch(noise, real);

    //        cout << ">" << e << ", " << i << "/" << BATCHES_PER_EPOCH << setprecision(4) << fixed << " d1=" << get<0>(realTrainRes) << " d2=" << get<0>(fakeTrainRes) << " g=" << get<0>(ganTrainRes) << endl;
    //    }

    //    gModel->Output().Map([](float x) { return x * 127.5f + 127.5f; }).Reshaped(Shape(32, 32, 3, -1)).SaveAsImage("cifar_gan_" + to_string(e) + ".png", false);
    //}
    

    //SaveCifar10Data("data/cifar10_data.bin", images, labels);

    // tensor image-related operations
    /*Tensor t(Shape(50, 50, 1));
    t.FillWithRand(-1, 0, 1);
    t.SaveAsImage("test.bmp", true);

    t.UpSample2D(2).SaveAsImage("test_x2.bmp", true);
    t.Conv2D(Tensor({1,1,1,1,-8,1,1,1,1,}, Shape(3,3,1)), 1, 0).NormalizedMinMax(EAxis::Global).SaveAsImage("test_conv.bmp", true);
    t.Conv2DTransposed(Tensor({ 1,1,1,1,-8,1,1,1,1, }, Shape(3, 3, 1)), 1, 1, 0).NormalizedMinMax(EAxis::Global).SaveAsImage("test_deconv.bmp", true);
    t.Pool2D(2, 2, EPoolingMode::Max, 0).SaveAsImage("test_maxpool.bmp", true);*/

    return 0;
}