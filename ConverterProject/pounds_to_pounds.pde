void setup() 
{
  fill(200);
  size(1040, 400);
}
void draw() 
{
  background(100);
  float weight = ChangetoPoundsofGold(mouseX*20+10);
  rect(0, 80, mouseX, 60);
  text("British Pound Sterling = " + int(mouseX*20+10), 440, 270);
  text("Pounds of Gold = " + ChangetoPoundsofGold(mouseX*20+10), 440, 290);
  drawReference(10, 200);
  textSize(26);
  text("Pounds to Pounds", 410, 30);
  textSize(12);
  text("by Gabriel Krivian", 470, 55);
  text("To operate simply slide bar left or right to convert British pounds to pounds of gold of equal value", 235, 350);
}

float ChangetoPoundsofGold(float BritishPound) 
{
  float ChangetoPoundsofGold = (BritishPound/16761);
  return ChangetoPoundsofGold;
}
void drawReference(int xpos, int ypos) 
{
  stroke(255);
  line(0, ypos, 1000, ypos);
  for (int i = 0; i<1100; i=i+100) 
  {
    text(i*20, xpos+i-10, ypos);
    line(xpos+i-10, ypos, xpos+i-10, ypos+5);
  }
}
/*price of pound of gold in us dollars is 27,000
 US dollar to Pound sterling is 1 to 0.62
 pound of gold is 16761 pounds*/

