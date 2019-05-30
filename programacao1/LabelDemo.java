import java.awt.BorderLayout;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JFrame;

public class LabelDemo
{
	public static void main( String args[])
	{
		//cria um rótulo com texto simples
		JLabel northLabel = new JLabel("North");
		
		//cria um incone de uma imagem para podermos colocar em um JLabel
		ImageIcon labelIcon = new ImageIcon("Dead (1).png");
		
		//cria um rótulo com um Icon em vez de texto
		JLabel centerLabel = new JLabel(labelIcon);
		
		//cria outro rótulo com um Icon
		JLabel southLabel = new JLabel(labelIcon); 
		
		//configura o rótulo para ixibir texto (bem como um icone)
		southLabel.setText("south");

		//cria um frame para armazenar os rótulos
		JFrame application = new JFrame();
		
		application.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE);
		//adiciona os rótulos ao frame; o segundo argumento especifica
		//onde adicionar o rótulo no frame
		application.add( northLabel, BorderLayout.NORTH);
		application.add( centerLabel, BorderLayout.CENTER);
		application.add( southLabel,  BorderLayout.SOUTH);

		application.setSize(900, 900);
		application.setVisible(true);
	}
}
