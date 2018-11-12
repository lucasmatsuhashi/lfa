import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class ER extends JFrame {
    public static void main(String[] args) throws FileNotFoundException,IOException {

        PrintStream console = System.out;

        File file = new File("C:/Users/Lucas/Desktop/codes/lfa/AFN-E/in_regular.txt");
        FileOutputStream fos = new FileOutputStream(file);
        PrintStream ps = new PrintStream(fos);
        System.setOut(ps);

        JFrame frameER = new JFrame("INPUT - ER");
        JPanel painel = new JPanel();
        JPanel painelER = new JPanel();
        JPanel painelWord = new JPanel();
        JPanel painelbutton = new JPanel();
        JTextField textER = new JTextField(30);
        JTextField textWord = new JTextField(30);
        JLabel labelER = new JLabel("EXPRESSAO:");
        JLabel labelWord = new JLabel("PALAVRA:");
        JButton buttonER = new JButton("OK");

        frameER.setSize(900,300);

        //set panels

        painel.setPreferredSize(new Dimension(900,350));
        painelER.setPreferredSize(new Dimension(900,80));
        painelWord.setPreferredSize(new Dimension(900,80));
        painelbutton.setPreferredSize(new Dimension(900,130));
        painelER.setBorder(new EmptyBorder(10,10,10,10));
        painelWord.setBorder(new EmptyBorder(10,10,10,10));
        painelbutton.setBorder(new EmptyBorder(10,10,10,10));

        //set textfields

        textER.setFont(textER.getFont().deriveFont(18.0f));
        textWord.setFont(textER.getFont().deriveFont(18.0f));
        textER.setPreferredSize(new Dimension(600,50));
        textWord.setPreferredSize(new Dimension(600,50));
        //set labels

        labelER.setFont(textER.getFont().deriveFont(18.0f));
        labelWord.setFont(textER.getFont().deriveFont(18.0f));
        labelER.setPreferredSize(new Dimension(150,50));
        labelWord.setPreferredSize(new Dimension(150,50));

        //set button

        buttonER.setPreferredSize(new Dimension(250,130));
        buttonER.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String stringER = textER.getText();
                String stringWord = textWord.getText();

                System.out.println(stringER);
                System.out.println(stringWord);
                frameER.dispose();
            }
        });

        painelER.add(labelER);
        painelER.add(textER);
        painelWord.add(labelWord);
        painelWord.add(textWord);
        painel.add(painelER);
        painel.add(painelWord);
        painelbutton.add(buttonER);

        painel.add(painelER);
        painel.add(painelWord);
        painel.add(painelbutton);

        frameER.add(painel);

        frameER.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frameER.pack();
        frameER.setLocationRelativeTo(null);
        frameER.setResizable(false);
        frameER.setVisible(true);
    }
}
