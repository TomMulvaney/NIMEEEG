#include "maximilian.h"

//Bizarelly, this sounds a little bit like Kraftwerk's 'Metropolis', although it isn't. Funny that.

maxiOsc sound,bass,timer,mod,lead,lead2,leadmod;//here are the synth bits
maxiEnv envelope, leadenvelope;//some envelopes
maxiFilter filter, filter2;//some filters
maxiDelayline delay;//a delay
convert mtof;//a method for converting midi notes to frequency
double bassout,leadout, delayout;//some variables to hold the data and pass it around
int trigger, trigger2, newnote;//some control variables
int currentCount,lastCount,playHead=0, currentChord=0;//some other control variables
int pitch[8]={57,57,59,60};//the bassline for the arpeggio
int chord[8]={0,0,7,2,5,5,0,0};//the root chords for the arpeggio
float currentPitch,leadPitch;//the final pitch variables

//here's the lead line trigger array, followed by the pitches
int leadLineTrigger[256]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int leadLinePitch[15]={69,67,65,64,67,66,64,62,65,64,62,57,55,60,57};
//int leadLinePitch[5]={69,67,65,64,67};
//int leadLinePitch[15]={57,60,55,57,62,64,65,62,64,66,67,64,65,67,69};

maxiOsc bassSine1, bassSine2, bassSine3;
maxiOsc ampSine1, ampSine2, ampPhasor;

void setup() {//some inits

}

void play(double *output) {//this is where the magic happens. Very slow magic.

    //*output = bassSine1.sinewave(bassSine2.sinewave(bassSine3.sinewave(0.1)*30)*440);
    *output=ampSine1.sinewave(440)*ampSine2.sinewave(ampPhasor.phasor(0.1,0,440));
    
    /*
	currentCount=(int)timer.phasor(9);//this sets up a metronome that ticks every so often
    
	if (lastCount!=currentCount) {//if we have a new timer int this sample, play the sound
		trigger=1;//play the arpeggiator line
		trigger2=leadLineTrigger[playHead%256];//play the lead line
		if (trigger2==1) {//if we are going to play a note
			leadPitch=mtof.mtof(leadLinePitch[newnote]);//get the next pitch val
			newnote++;//and iterate
			if (newnote>sizeof(leadLinePitch)/sizeof(*leadLinePitch)) {
				newnote=0;//make sure we don't go over the edge of the array
			}
		}
		currentPitch=mtof.mtof(pitch[(playHead%4)]+chord[currentChord%8]);//write the frequency val into currentPitch
		playHead++;//iterate the playhead
		if (playHead%32==0) {//wrap every 4 bars
			currentChord++;//change the chord
		}
		//cout << "tick\n";//the clock ticks
		lastCount=0;//set lastCount to 0
	}
    
	bassout=filter2.lores(envelope.adsr(bass.saw(currentPitch*0.5)+sound.pulse(currentPitch*0.5,mod.phasor(1)),1,0.9995, 0.25, 0.9995, 1, trigger),9250,2);//new, simple ADSR.
	leadout=filter.lores(leadenvelope.ar(lead2.saw(leadPitch*4)+lead.pulse(leadPitch+(leadmod.sinebuf(1.9)*1.5), 0.6), 0.00005, 0.999975, 50000, trigger2),5900,10);//leadline
    
	delayout=(leadout+(delay.dl(leadout, 14000, 0.8)*0.5))/2;//add some delay
    //delayout=leadout;
    
	if(trigger!=0)trigger=0;//set the trigger to off if you want it to trigger immediately next time.
    
    
    double combined = (bassout+delayout)/2;
    output[0]=combined;
    output[1]=combined;
    
	//output[0]=(bassout+delayout);//sum output
	//output[1]=(bassout+delayout);
     */
    
}