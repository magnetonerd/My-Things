#define Iterator typename
#define Number typename
#define Fraction typename

//template<Iterator I, Number N>
struct SampleSpace{
  int *sample_loc; //Memory location of sample outcome
  int sample_size; //Number of occurances of sample outcome
};

//template<Iterator I, Fraction F>
struct ProbabilitySpace{
  int *prob_loc; //Memory location of sample outcome probability
  double prob_value; //Probability of occurances of sample outcome at *sample_loc
};
