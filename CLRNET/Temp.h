#pragma once

namespace CLRNET {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Temp
	/// </summary>
	public ref class Temp : public System::Windows::Forms::Form
	{
	public:
		Temp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Temp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ SummaryPanel;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ lblSummaryHeading;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	protected:



























	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->SummaryPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblSummaryHeading = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->SummaryPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// SummaryPanel
			// 
			this->SummaryPanel->Controls->Add(this->panel1);
			this->SummaryPanel->Controls->Add(this->chart1);
			this->SummaryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SummaryPanel->Location = System::Drawing::Point(0, 0);
			this->SummaryPanel->Name = L"SummaryPanel";
			this->SummaryPanel->Size = System::Drawing::Size(1084, 613);
			this->SummaryPanel->TabIndex = 8;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label22);
			this->panel1->Controls->Add(this->panel7);
			this->panel1->Controls->Add(this->panel6);
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->lblSummaryHeading);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(997, 334);
			this->panel1->TabIndex = 3;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label22->Location = System::Drawing::Point(175, 6);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(73, 17);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Date Here";
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->label21);
			this->panel7->Location = System::Drawing::Point(21, 43);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(372, 144);
			this->panel7->TabIndex = 7;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(102, 61);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(124, 20);
			this->label21->TabIndex = 3;
			this->label21->Text = L"Weather Code";
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label34);
			this->panel6->Controls->Add(this->label33);
			this->panel6->Controls->Add(this->label20);
			this->panel6->Controls->Add(this->label19);
			this->panel6->Controls->Add(this->label18);
			this->panel6->Location = System::Drawing::Point(21, 193);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(372, 135);
			this->panel6->TabIndex = 6;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(23, 101);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(51, 16);
			this->label34->TabIndex = 5;
			this->label34->Text = L"label34";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(251, 101);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(51, 16);
			this->label33->TabIndex = 4;
			this->label33->Text = L"label33";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(260, 64);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(32, 16);
			this->label20->TabIndex = 2;
			this->label20->Text = L"Max";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(33, 64);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(28, 16);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Min";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(125, 15);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(100, 20);
			this->label18->TabIndex = 0;
			this->label18->Text = L"Temperature";
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->label32);
			this->panel5->Controls->Add(this->label31);
			this->panel5->Controls->Add(this->label17);
			this->panel5->Controls->Add(this->label16);
			this->panel5->Controls->Add(this->label15);
			this->panel5->Location = System::Drawing::Point(400, 193);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(231, 135);
			this->panel5->TabIndex = 5;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(138, 101);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(51, 16);
			this->label32->TabIndex = 5;
			this->label32->Text = L"label32";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(138, 58);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(51, 16);
			this->label31->TabIndex = 4;
			this->label31->Text = L"label31";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(16, 101);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(91, 16);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Clear sky max";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(16, 58);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 16);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Max";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(74, 17);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(75, 20);
			this->label15->TabIndex = 0;
			this->label15->Text = L"UV Index";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->label24);
			this->panel4->Controls->Add(this->label23);
			this->panel4->Controls->Add(this->label14);
			this->panel4->Controls->Add(this->label13);
			this->panel4->Controls->Add(this->label12);
			this->panel4->Location = System::Drawing::Point(400, 43);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(229, 144);
			this->panel4->TabIndex = 4;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(138, 97);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(51, 16);
			this->label24->TabIndex = 4;
			this->label24->Text = L"label24";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(138, 61);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(51, 16);
			this->label23->TabIndex = 3;
			this->label23->Text = L"label23";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(7, 97);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(71, 16);
			this->label14->TabIndex = 2;
			this->label14->Text = L"Probability";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(7, 61);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(59, 16);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Average";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline));
			this->label12->Location = System::Drawing::Point(52, 17);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(96, 20);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Precipitation";
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label30);
			this->panel3->Controls->Add(this->label29);
			this->panel3->Controls->Add(this->label28);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Location = System::Drawing::Point(635, 193);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(347, 135);
			this->panel3->TabIndex = 3;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(106, 94);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(51, 16);
			this->label30->TabIndex = 6;
			this->label30->Text = L"label30";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(106, 64);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(51, 16);
			this->label29->TabIndex = 5;
			this->label29->Text = L"label29";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(282, 81);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(51, 16);
			this->label28->TabIndex = 4;
			this->label28->Text = L"label28";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(183, 81);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 16);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Direction";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(22, 94);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(41, 16);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Gusts";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(22, 66);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 16);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Speed";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(146, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 20);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Wind";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label27);
			this->panel2->Controls->Add(this->label26);
			this->panel2->Controls->Add(this->label25);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Location = System::Drawing::Point(635, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(347, 144);
			this->panel2->TabIndex = 2;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(282, 97);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(51, 16);
			this->label27->TabIndex = 7;
			this->label27->Text = L"label27";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(147, 97);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(51, 16);
			this->label26->TabIndex = 6;
			this->label26->Text = L"label26";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(12, 97);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(51, 16);
			this->label25->TabIndex = 5;
			this->label25->Text = L"label25";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(147, 56);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 16);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Duration";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(282, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 16);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Sunset";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(11, 56);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 16);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Sunrise";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(112, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(149, 20);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Sunrise and Sunset";
			// 
			// lblSummaryHeading
			// 
			this->lblSummaryHeading->AutoSize = true;
			this->lblSummaryHeading->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblSummaryHeading->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblSummaryHeading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSummaryHeading->Location = System::Drawing::Point(0, 0);
			this->lblSummaryHeading->Name = L"lblSummaryHeading";
			this->lblSummaryHeading->Size = System::Drawing::Size(169, 26);
			this->lblSummaryHeading->TabIndex = 0;
			this->lblSummaryHeading->Text = L"Today\'s Weather";
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Bottom;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 374);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::EarthTones;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1084, 239);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// Temp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 613);
			this->Controls->Add(this->SummaryPanel);
			this->Name = L"Temp";
			this->Text = L"Temp";
			this->Load += gcnew System::EventHandler(this, &Temp::Temp_Load);
			this->SummaryPanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Temp_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
