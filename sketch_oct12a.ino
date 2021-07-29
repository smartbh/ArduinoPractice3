char sing[]="IIpLLLpKpJJp LLpIIpGGpIIp LLpMpNpOOOpNpMMMMMMp\
             PPPpOpNNpMMp LLpKpJpIIpGGp IIpLLpMpMpNNpLLLLLLp";

// 아래 freq는 절대 변경하지 마라
int   freq[ ]= {131, 149, 165, 175, 196, 220, 247};
int   piezo= 7;

void setup() {
  
  pinMode(piezo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int interval= 200;
  for(int i=0;i<sizeof(sing);i++){

    if(sing[i] != 'p' && (sing[i] < 'A' || sing[i]>'Z'))  continue;
    if(sing[i] == 'p'){
      delay(50);
      continue;
    }
    
    int f;
    switch(sing[i]){
      case 'I': f = freq[1]*2;
        break;
        //4옥타브 레
      case 'L' : f = freq[4]*2;
        break;
        //4옥타브 솔
      case 'K' : f = freq[3]*2;
        break;
        //4옥타브 파
       case 'J' : f = freq[2]*2;
        break;
        //4옥타브 미
      case 'G' : f = freq[6];
        break;
        //3옥타브 시
      case 'M' : f = freq[5]*2;
        break;
        //4옥타브 라
      case 'N' : f = freq[6]*2;
        break;
        //4옥타브 시
      case 'O' : f = freq[0]*2*2;
        break;
        //5옥타브 도
      case 'P' : f = freq[1]*2*2;
        break;
        //5옥타브 레
    }
    // 여기서 적절한 f의 값을 계산하라.
    
    tone(piezo, f, 300);
    delay(300);
  }
  delay(2000);
}
