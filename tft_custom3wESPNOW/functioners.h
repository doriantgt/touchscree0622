

class Functioner{
  public:
  
  
  virtual void go(){
    //  cout << "parent" << endl;
  //   (this->*methodPtr)();
  }

   
};
class textBoxValuePrinter { //checks weather value has changed to print new value to screen
public:
//static TFT_eSPI *screen; //the syntax for static members is pretty bad I do not recomend

int16_t lastValue;
int16_t *value;


};

class ValueChangeFunctioner: public Functioner{
    public:
    //static TFT_eSPI * screen; //the syntax for static members is pretty bad I do not recomend
  int16_t incriment;
  int16_t minimum ;
  int16_t maximum;
  
  int16_t *valuePtr;// = nullptr;
     bool hasChanged; //used to tell listeners that this value has changed

  void (ValueChangeFunctioner::*methodPtr)();
  
 
  virtual void go(){
            
            (this->*methodPtr)();
        
  }
  void assignValueChange(int16_t &inValue, int16_t inc, int16_t min , int16_t max){
      if(min > max){ //swap 
          int16_t temp = min; min = max; max = temp;
      }
   valuePtr = &inValue; incriment = inc; minimum = min; maximum = max;
   methodPtr = &ValueChangeFunctioner::valueChange;

  }
  void valueChange(){
      
      int32_t bigValue = *valuePtr;
      bigValue += incriment;
      
      if(bigValue > maximum ){
          bigValue = maximum;
      }else if( bigValue < minimum){
          bigValue = minimum;
      }
      
       *valuePtr = bigValue;

     // cout << " valuePtr  "<< *valuePtr  << endl;
  }
    void assignRangeStepChange(int16_t &inValue, int inc, int min , int max){
          if(min > max){ //swap 
          int16_t temp = min; min = max; max = temp;
      }
   valuePtr = &inValue; incriment = inc; minimum = min; maximum = max;
   methodPtr = &ValueChangeFunctioner::rangeStepChange;
  }
  void rangeStepChange(){
      
      *valuePtr *= incriment;
   //   cout << "  bitches  "<< *valuePtr  << endl;
  }
  
};