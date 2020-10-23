using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        private SerialPort port;
        private static string port_name = "COM4";
        private static int baud_rate = 9600;
        private int led_state = 0b000000;
        private static int RED = 0b000001;
        private static int GREEN = 0b000010;
        private static int ARD_LED = 0b000100;

        public Form1()
        {
            InitializeComponent();

            if (port == null)
            {
                port = new SerialPort(port_name, baud_rate);
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            led_state ^= RED;
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            led_state ^= GREEN;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            led_state ^= ARD_LED;
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if(port != null)
            {
                port.Open();
            }
            if (port.IsOpen)
            {
                port.Write(led_state.ToString());
                port.Close();
            }
        }


    }
}
