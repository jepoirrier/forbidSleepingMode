using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace forbidSleepingMode
{
    public partial class mainForm : Form
    {
        [DllImport ("kernel32.dll")]
        public static extern uint SetThreadExecutionState(uint esFlag);

        public mainForm()
        {
            InitializeComponent();
        }

        private void mainForm_Load(object sender, EventArgs e)
        {
            resetIdleTimer.Interval = 10 * 60 * 1000; // 10 minutes * 60 s/m * 1000 ms/s
            resetIdleTimer.Start();
        }

        private void resetIdleTimer_Tick(object sender, EventArgs e)
        {
            SetThreadExecutionState(0x00000002);
            //MessageBox.Show("Hello");
        }
    }
}
