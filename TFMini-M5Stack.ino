#include <M5Stack.h>
#include "TFMini.h"

TFMini tfmini;
// M5Stack 起動時にのみ走る処理
void setup(){

  M5.begin();
  M5.Power.begin();

  // PC と M5Stack の間のシリアル通信を設定
  Serial.begin(115200);
  while (!Serial);
  Serial.println ("Initializing...");

  // M5Stack と TFMini の間のシリアル通信 
  Serial2.begin(TFMINI_BAUDRATE); // 115200
  while (!Serial2);
  tfmini.begin(&Serial2);  
}

// 無限ループで実行され続ける処理
void loop() {
  // TFMini から測定値を取得
  uint16_t dist = tfmini.getDistance();
  uint16_t strength = tfmini.getRecentSignalStrength();

  // 測定値を PC に表示
  // Serial.print(dist);
  // Serial.print(" cm      sigstr: ");
  // Serial.println(strength);

  // 測定値を M5Stack に表示
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextSize(3);

  M5.Lcd.printf("Distance: %i cm \r\n",dist);
  M5.Lcd.printf("Strength: %i \r\n",strength);
   // 100 ミリ秒 = 0.1 秒待つ
  delay(100);
}
