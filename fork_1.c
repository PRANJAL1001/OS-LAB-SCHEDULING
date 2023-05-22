import java.applet.*;
import java.awt.*;

public class UserInfoApplet extends Applet {
    String rollNo = "123456";
    String name = "John Doe";
    String branch = "Computer Science";
    String section = "A";

    public void paint(Graphics g) {
        g.drawString("Roll No.: " + rollNo, 20, 20);
        g.drawString("Name: " + name, 20, 40);
        g.drawString("Branch: " + branch, 20, 60);
        g.drawString("Section: " + section, 20, 80);
    }
}