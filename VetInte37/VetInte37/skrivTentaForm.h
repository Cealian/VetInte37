#pragma once
#include "Fråga.h";

namespace Forms{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Common;
	using namespace System::Configuration;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for skrivTentaForm
	/// </summary>
	public ref class skrivTentaForm : public System::Windows::Forms::Form
	{
	public:

		
		
		skrivTentaForm(void)
		{
			InitializeComponent();

			_antalRätt = 0;

			//
			//TODO: Add the constructor code here
			//
		}


		void setVars(DbCommand ^ cmd, String ^ examenString)
		{
			_cmd = cmd;

			_examensID = examenString->Split('-')[0]->ToString()->Trim();
			_ämne = examenString->Split('-')[1]->ToString()->Trim();
			_poäng = examenString->Split('-')[2]->ToString()->Trim();
			_kurskod = examenString->Split('-')[3]->ToString()->Trim();

			lblDetails->Text = "ExamensID: "+_examensID
				+"\nÄmne: "+_ämne
				+"\nPoäng: "+_poäng
				+"\nKurskod: "+_kurskod;

			_fråga = gcnew Fråga();
			_frågeNo = 1;

			showQuestion();
		}

		void showQuestion()
		{
			_fråga->setDetails(_cmd,_frågeNo,_examensID);
			lblQuestion->Text = _fråga->getText();
			
			radA1->Text = _fråga->getAnswer(1);
			radA2->Text = _fråga->getAnswer(2);
			radA3->Text = _fråga->getAnswer(3);
			radA4->Text = _fråga->getAnswer(4);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~skrivTentaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblDetails;
	private: System::Windows::Forms::Label^  lblQuestion;

	protected: 

	private: System::Windows::Forms::RadioButton^  radA1;
	private: System::Windows::Forms::RadioButton^  radA2;
	private: System::Windows::Forms::RadioButton^  radA3;
	private: System::Windows::Forms::RadioButton^  radA4;
	private: System::Windows::Forms::Button^  btnNext;






	private:

		DbCommand ^ _cmd;
		String ^ _examensID;
		String ^ _ämne;
		String ^ _poäng;
		String ^ _kurskod;
		Fråga ^ _fråga;
		int _frågeNo;
		int _antalRätt;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblDetails = (gcnew System::Windows::Forms::Label());
			this->lblQuestion = (gcnew System::Windows::Forms::Label());
			this->radA1 = (gcnew System::Windows::Forms::RadioButton());
			this->radA2 = (gcnew System::Windows::Forms::RadioButton());
			this->radA3 = (gcnew System::Windows::Forms::RadioButton());
			this->radA4 = (gcnew System::Windows::Forms::RadioButton());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblDetails
			// 
			this->lblDetails->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblDetails->Location = System::Drawing::Point(12, 9);
			this->lblDetails->Name = L"lblDetails";
			this->lblDetails->Size = System::Drawing::Size(114, 230);
			this->lblDetails->TabIndex = 0;
			// 
			// lblQuestion
			// 
			this->lblQuestion->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblQuestion->Location = System::Drawing::Point(132, 9);
			this->lblQuestion->Name = L"lblQuestion";
			this->lblQuestion->Size = System::Drawing::Size(333, 103);
			this->lblQuestion->TabIndex = 1;
			// 
			// radA1
			// 
			this->radA1->AutoSize = true;
			this->radA1->Checked = true;
			this->radA1->Location = System::Drawing::Point(132, 115);
			this->radA1->Name = L"radA1";
			this->radA1->Size = System::Drawing::Size(53, 17);
			this->radA1->TabIndex = 2;
			this->radA1->TabStop = true;
			this->radA1->Text = L"Svar1";
			this->radA1->UseVisualStyleBackColor = true;
			// 
			// radA2
			// 
			this->radA2->AutoSize = true;
			this->radA2->Location = System::Drawing::Point(132, 138);
			this->radA2->Name = L"radA2";
			this->radA2->Size = System::Drawing::Size(53, 17);
			this->radA2->TabIndex = 3;
			this->radA2->TabStop = true;
			this->radA2->Text = L"Svar2";
			this->radA2->UseVisualStyleBackColor = true;
			// 
			// radA3
			// 
			this->radA3->AutoSize = true;
			this->radA3->Location = System::Drawing::Point(132, 161);
			this->radA3->Name = L"radA3";
			this->radA3->Size = System::Drawing::Size(53, 17);
			this->radA3->TabIndex = 4;
			this->radA3->TabStop = true;
			this->radA3->Text = L"Svar3";
			this->radA3->UseVisualStyleBackColor = true;
			// 
			// radA4
			// 
			this->radA4->AutoSize = true;
			this->radA4->Location = System::Drawing::Point(132, 184);
			this->radA4->Name = L"radA4";
			this->radA4->Size = System::Drawing::Size(53, 17);
			this->radA4->TabIndex = 5;
			this->radA4->TabStop = true;
			this->radA4->Text = L"Svar4";
			this->radA4->UseVisualStyleBackColor = true;
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(390, 213);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(75, 23);
			this->btnNext->TabIndex = 6;
			this->btnNext->Text = L"Nästa";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &skrivTentaForm::btnNext_Click);
			// 
			// skrivTentaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 248);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->radA4);
			this->Controls->Add(this->radA3);
			this->Controls->Add(this->radA2);
			this->Controls->Add(this->radA1);
			this->Controls->Add(this->lblQuestion);
			this->Controls->Add(this->lblDetails);
			this->Name = L"skrivTentaForm";
			this->Text = L"skrivTentaForm";
			this->Load += gcnew System::EventHandler(this, &skrivTentaForm::skrivTentaForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void skrivTentaForm_Load(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }
private: System::Void btnNext_Click(System::Object^  sender, System::EventArgs^  e) {
			 if ((_fråga->getRättSvar() == 1 && radA1->Checked) ||
				 (_fråga->getRättSvar() == 2 && radA2->Checked) ||
				 (_fråga->getRättSvar() == 3 && radA3->Checked) ||
				 (_fråga->getRättSvar() == 4 && radA4->Checked))
			 {
				 _antalRätt++;
			 }

			 if (_fråga->noOfQuestions()>_frågeNo)
			 {
				 if (_fråga->noOfQuestions() == _frågeNo-1)
				 {
					 btnNext->Text == "Klar";
				 }
				 _frågeNo++;
				 showQuestion();
			 }
			 else
			 {
				 _frågeNo++;

				 String ^ resultat = "Inte godkänt...";

				 int minGodkänt = (_frågeNo*0.4);

				 if (_antalRätt >= minGodkänt)
				 {
					 resultat = "Godkänt!";
				 }

				 MessageBox::Show(resultat + "\n"
					 + "Antal rätt: " + _antalRätt + "\n"
					 + "Antal frågor: " + _frågeNo + "\n"
					 + "Godkänt: " + minGodkänt);
			 }


		 }
};
}
