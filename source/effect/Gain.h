//
// Created by maple on 25-5-19.
//

#ifndef TEST_H
#define TEST_H

#include "./ProcessorBase.h"
#include <juce_audio_processors/juce_audio_processors.h>

class Gain  : public ProcessorBase, public juce::AudioProcessorValueTreeState::Listener
{
public:
    Gain(juce::AudioProcessorValueTreeState& apvts):Apvts(apvts)
    {
        Apvts.addParameterListener("gainSlider", this);


    }

    ~Gain()
    {
        Apvts.removeParameterListener("gainSlider", this);
    }

    void parameterChanged(const juce::String& parameterID, float newValue)
    {
        if (parameterID.equalsIgnoreCase("gainSlider"))
        {
            juce::Logger::outputDebugString("gain =" + juce::String(gain));
            gain = newValue;
         }
    }

    void init(juce::AudioProcessorValueTreeState &apvts) override
    {

    }

    void prepareToPlay(double sampleRate, int samplesPerBlock) override
    {

        gain = Apvts.getParameterAsValue("gainSlider").getValue();
    }

    void processBlock(juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override
    {
        buffer.applyGain (gain);
    }

    void reset() override
    {

    }


    const juce::String getName() const override { return "test"; }

private:

    float  gain;
    juce::AudioProcessorValueTreeState& Apvts;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gain)
};


#endif //TEST_H
