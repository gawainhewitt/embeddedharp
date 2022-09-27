boolean bigMenu = false;


void drawMenu() {
  u8g2.firstPage();
  do {
    draw();
  } while ( u8g2.nextPage() );
}

void draw() {
  if (bigMenu) {
    u8g2.setFont(u8g2_font_inr21_mr);
    u8g2.setCursor(1, 30);
    u8g2.print("C");
    u8g2.setCursor(1, 60);
    u8g2.print("Major");
  } else {
    u8g2.setFont(u8g2_font_6x13_tr);
    
    u8g2.setCursor(1, 10);
    u8g2.print("Scale: "); 
    u8g2.print("C"); 
    u8g2.print(" "); 
    u8g2.print("Major");
    
    u8g2.setCursor(1, 20);
    u8g2.print("Notes: "); u8g2.print(6);

    u8g2.setCursor(1, 30);
    u8g2.print("Min Dist(cm): "); u8g2.print(12);

    u8g2.setCursor(1, 40);
    u8g2.print("Max Dist(cm): "); u8g2.print(32);

    u8g2.setCursor(1, 50);
    u8g2.print("Inst: "); u8g2.print(32); u8g2.print("  Bank: "); u8g2.print(4);

    u8g2.setCursor(1, 60);
    u8g2.print("Volume: "); u8g2.print(34);
    
    // u8g2.drawFrame(0, activeMenuInput * 10, 127, 10);
  }
}
