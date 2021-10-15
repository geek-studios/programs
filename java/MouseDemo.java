import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class MouseDemo implements MouseListener
{
  JFrame f;
  JLabel l;
  MouseDemo()
  {
   f=new JFrame();
   f.addMouseListener(this);
   l=new JLabel();
   f.add(l);
   f.setSize(400,400);
   f.setLayout(new FlowLayout());
   f.setVisible(true);
   
  }
  public void mouseClicked(MouseEvent e)
  {
    l.setText("mouse clicked");
  }
  public void mousePressed(MouseEvent e)
  {
    l.setText("mouse pressed");
  }
  public void mouseReleased(MouseEvent e)
  {
    l.setText("mouse released");
  }
  public void mouseEntered(MouseEvent e)
  {
    l.setText("mouse entered");
  }
  public void mouseExited(MouseEvent e)
  {
    l.setText("mouse exited");
  }
  public static void main(String[]args)
  {
    new MouseDemo();
  }
}