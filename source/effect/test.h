//
// Created by maple on 25-5-19.
//

#ifndef TEST_H
#define TEST_H

#include <juce_audio_processors/juce_audio_processors.h>

class test  : public ProcessorBase, public juce::AudioProcessorValueTreeState::Listener
{
public:
    test(juce::AudioProcessorValueTreeState& apvts):Apvts(apvts)
    {

    }

    ~test()
    {
        // Apvts->removeParameterListener("FilterComboBox", this);
    }

    void parameterChanged(const juce::String& parameterID, float newValue)
    {
        // if (parameterID.equalsIgnoreCase("FilterComboBox"))
        // {
        //     juce::Logger::outputDebugString("FilterComboBox =" + FilterModitems[(size_t)newValue]);
        //     // juce::Logger::outputDebugString("FilterComboBox =" + juce::String((size_t)newValue));
        //     proEq_Unit.filter[filter_index].filter_mod = newValue;
        // }
    }

    void init(juce::AudioProcessorValueTreeState &apvts) override
    {

    }

    void prepareToPlay(double sampleRate, int samplesPerBlock) override
    {

    }

    void processBlock(juce::AudioSampleBuffer& buffer, juce::MidiBuffer&) override
    {

    }

    void reset() override
    {

    }


    const juce::String getName() const override { return "Comb Filter"; }

private:

    juce::AudioProcessorValueTreeState& Apvts;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (test)
};


#endif //TEST_H
