import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class Calculator implements ActionListener {
       JFrame jf;
       JButton addBtn, subBtn, mulBtn, divBtn, modBtn, clearBtn, equalBtn;
       ArrayList<JButton> numberBtn = new ArrayList<JButton>() {
       };
       JTextField textField;
       String errorMsg = "";

       Calculator() {
              GridLayout grid1 = new GridLayout(6, 3);
              jf = new JFrame("Calculator");
              addBtn = new JButton("+");
              subBtn = new JButton("-");
              mulBtn = new JButton("*");
              divBtn = new JButton("/");
              modBtn = new JButton("%");
              clearBtn = new JButton("Clear");
              equalBtn = new JButton("=");

              textField = new JTextField();
              
              jf.add(textField);

              for (int i = 0; i < 10; i++) {
                     JButton btn = new JButton(String.valueOf(i));
                     jf.add(btn);
                     numberBtn.add(btn);
                     btn.addActionListener(this);
              }

              jf.add(addBtn);
              jf.add(subBtn);
              jf.add(mulBtn);
              jf.add(divBtn);
              jf.add(modBtn);
              jf.add(clearBtn);
              jf.add(equalBtn);

              jf.setSize(500, 500);
              jf.setVisible(true);
              jf.setLayout(grid1);
              
              addBtn.addActionListener(this);
              subBtn.addActionListener(this);
              mulBtn.addActionListener(this);
              divBtn.addActionListener(this);
              clearBtn.addActionListener(this);
              equalBtn.addActionListener(this);
              modBtn.addActionListener(this);
       }

       public void actionPerformed(ActionEvent ae) {
              boolean btnPresent = false;

              for (JButton btn : numberBtn) {
                     if (ae.getSource() == btn) {
                            if (errorMsg != "") {
                                   textField.setText("");
                                   errorMsg = "";
                            }
                            String currentText = textField.getText();

                            if (currentText.contains("="))
                                   currentText = "";

                            textField.setText(currentText + btn.getText());
                            btnPresent = true;
                            break;
                     } 
              }

              if (!btnPresent) {
                     if (ae.getSource() == addBtn) {
                            String currentText = textField.getText();
                            if (checkValid())
                                   textField.setText(currentText + " " + addBtn.getText() + " ");
                     }

                     else if (ae.getSource() == subBtn) {
                            String currentText = textField.getText();
                            if (checkValid())
                                   textField.setText(currentText + " " + subBtn.getText() + " ");
                     }

                     else if (ae.getSource() == mulBtn) {
                            String currentText = textField.getText();
                            if (checkValid())
                                   textField.setText(currentText + " " + mulBtn.getText() + " ");
                     }

                     else if (ae.getSource() == divBtn) {
                            String currentText = textField.getText();
                            if (checkValid())
                                   textField.setText(currentText + " " + divBtn.getText() + " ");
                     }

                     else if (ae.getSource() == modBtn) {
                            String currentText = textField.getText();
                            if (checkValid())
                                   textField.setText(currentText + " " + modBtn.getText() + " ");
                     }

                     else if (ae.getSource() == clearBtn)
                            textField.setText("");

                     else if (ae.getSource() == equalBtn) {
                            int result = 0;
                            String operation = "";
                            String val = textField.getText();
                            if (!val.isEmpty()) {
                                   String[] num = val.split(" ");
                                   for (int i = 0; i < num.length; i++) {
                                          switch (num[i]) {
                                                 case "+":
                                                        operation = "+";
                                                        break;
                                                 case "-":
                                                        operation = "-";
                                                        break;
                                                 case "*":
                                                        operation = "*";
                                                        break;
                                                 case "/":
                                                        operation = "/";
                                                        break;
                                                 case "%":
                                                        operation = "%";
                                                        break;
                                                 default:
                                                        int number = Integer.parseInt(num[i]);
                                                        if (operation == "+")
                                                               result = result + number;
                                                        else if (operation == "-")
                                                               result = result - number;
                                                        else if (operation == "*")
                                                               result = result * number;
                                                        else if (operation == "/") {
                                                               try {
                                                                      result = result / number;
                                                               } catch (ArithmeticException e) {
                                                                      System.out.println("cannot divide numbers");
                                                                      errorMsg = "Arithmetic Error";
                                                               }
                                                        } else if (operation == "%")
                                                               result = result % number;
                                                        else
                                                               result = number;
                                                        break;
                                          }
                                   }
                                   if (errorMsg == "")
                                          textField.setText(textField.getText() + " = " + String.valueOf(result));
                                   else
                                          textField.setText(errorMsg);
                            }
                     }
              }
       }

       boolean checkValid() {
              if (errorMsg != "") {
                     textField.setText("");
                     errorMsg = "";
              }
              String text = textField.getText();
              if (text.contains("="))
                     text = "";
              boolean isNumber = false;
              String[] parts = text.replaceAll(" ", "").split("");
              for (int i = 0; i < 10; i++) {
                     if (parts[parts.length - 1].equals(String.valueOf(i))) {
                            isNumber = true;
                            break;
                     }
              }
              return !text.isEmpty() && isNumber;
       }

}

class GuiCalculator {
       public static void main(String args[]) {
              Calculator cal = new Calculator();
       }
}