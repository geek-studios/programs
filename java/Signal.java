import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class Signal implements ActionListener
{
  JFrame f;
  JRadioButton b1,b2,b3;
  static int option = 0;
  Traffic t;
 public Signal()
{
 f = new JFrame("SIGNAL");
 f.setSize(750,750);
 f.setVisible(true);
 f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
 b1 = new JRadioButton("STOP");
 b1.setBounds(100,100,100,100);
 b1.addActionListener(this);
 f.add(b1);
 
 b2 = new JRadioButton("READY");
 b2.setBounds(100,200,100,100);
 b2.addActionListener(this);
 f.add(b2);
 
 b3 = new JRadioButton("GO");
 b3.setBounds(100,300,100,100);
 b3.addActionListener(this);
 f.add(b3);

 ButtonGroup bg = new ButtonGroup();
 bg.add(b1);
 bg.add(b2);
 bg.add(b3);

 t = new Traffic();
 f.add(t);
}
public void actionPerformed(ActionEvent ae)
{
 if(ae.getActionCommand() == "STOP")
  option = 1;
 else if(ae.getActionCommand() == "READY")
 option = 2;
 else
 option = 3;

 t.setVisible(false);
 t = new Traffic();
 f.add(t);
}
public static void main(String args[])
{
 Signal s = new Signal();
}
}
class Traffic extends JPanel
{
 public void paint(Graphics g)
{
  
  g.drawOval(300,150,100,100);
  g.drawOval(300,300,100,100);
  g.drawOval(300,450,100,100);
  
  //g.drawOval(0,0,30,50);
  //g.drawRect(0,0,100,000);
  //g.drawOval(0,0,20,20);
  if(Signal.option == 1)
   {
   g.setColor(Color.red);
   g.fillOval(300,150,100,100);
   }
 if(Signal.option == 2)
  {
    g.setColor(Color.yellow);
    g.fillOval(300,300,100,100);
  }
 if(Signal.option == 3)
  {
    g.setColor(Color.green);
    g.fillOval(300,450,100,100);
  }
}
}