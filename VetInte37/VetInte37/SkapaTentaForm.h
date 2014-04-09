#pragma once
#include "Fr�ga.h"
#include <cliext\vector>

namespace Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SkapaTentaForm
	/// </summary>
	public ref class SkapaTentaForm : public System::Windows::Forms::Form
	{
	public:
		SkapaTentaForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			_fr�gor = gcnew array<Fr�ga^>(250);
			_fr�geNo = 1;
		}

		void setCmd(DbCommand ^ cmd)
		{
			_cmd = cmd;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SkapaTentaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtID;
	protected: 
	private: System::Windows::Forms::TextBox^  txtKurskod;
	private: System::Windows::Forms::TextBox^  txt�mne;
	private: System::Windows::Forms::TextBox^  txtPo�ng;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtFr�ga;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  lblFr�geNo;
	private: System::Windows::Forms::TextBox^  txtSvar1;
	private: System::Windows::Forms::TextBox^  txtSvar2;
	private: System::Windows::Forms::TextBox^  txtSvar3;
	private: System::Windows::Forms::TextBox^  txtSvar4;




	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::RadioButton^  radSvar1;
	private: System::Windows::Forms::RadioButton^  radSvar2;
	private: System::Windows::Forms::RadioButton^  radSvar3;
	private: System::Windows::Forms::RadioButton^  radSvar4;
	private: System::Windows::Forms::Button^  button1;











	private:

		DbCommand ^ _cmd;
		int _fr�geNo;
		String ^ _examensID;
		array<Fr�ga^>^ _fr�gor;
	private: System::Windows::Forms::Button^  btnKlar;


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
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->txtKurskod = (gcnew System::Windows::Forms::TextBox());
			this->txt�mne = (gcnew System::Windows::Forms::TextBox());
			this->txtPo�ng = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtFr�ga = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblFr�geNo = (gcnew System::Windows::Forms::Label());
			this->txtSvar1 = (gcnew System::Windows::Forms::TextBox());
			this->txtSvar2 = (gcnew System::Windows::Forms::TextBox());
			this->txtSvar3 = (gcnew System::Windows::Forms::TextBox());
			this->txtSvar4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->radSvar1 = (gcnew System::Windows::Forms::RadioButton());
			this->radSvar2 = (gcnew System::Windows::Forms::RadioButton());
			this->radSvar3 = (gcnew System::Windows::Forms::RadioButton());
			this->radSvar4 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnKlar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtID
			// 
			this->txtID->Location = System::Drawing::Point(76, 24);
			this->txtID->Name = L"txtID";
			this->txtID->Size = System::Drawing::Size(156, 20);
			this->txtID->TabIndex = 0;
			// 
			// txtKurskod
			// 
			this->txtKurskod->Location = System::Drawing::Point(76, 50);
			this->txtKurskod->Name = L"txtKurskod";
			this->txtKurskod->Size = System::Drawing::Size(156, 20);
			this->txtKurskod->TabIndex = 1;
			// 
			// txt�mne
			// 
			this->txt�mne->Location = System::Drawing::Point(76, 76);
			this->txt�mne->Name = L"txt�mne";
			this->txt�mne->Size = System::Drawing::Size(156, 20);
			this->txt�mne->TabIndex = 2;
			// 
			// txtPo�ng
			// 
			this->txtPo�ng->Location = System::Drawing::Point(76, 102);
			this->txtPo�ng->Name = L"txtPo�ng";
			this->txtPo�ng->Size = System::Drawing::Size(57, 20);
			this->txtPo�ng->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"ExamensID:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Kurskod:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(33, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"�mne:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 105);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Po�ng:";
			// 
			// txtFr�ga
			// 
			this->txtFr�ga->Location = System::Drawing::Point(266, 28);
			this->txtFr�ga->Multiline = true;
			this->txtFr�ga->Name = L"txtFr�ga";
			this->txtFr�ga->Size = System::Drawing::Size(555, 137);
			this->txtFr�ga->TabIndex = 8;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtID);
			this->groupBox1->Controls->Add(this->txtKurskod);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->txt�mne);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->txtPo�ng);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(3, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(257, 153);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Tentamensinformation";
			// 
			// lblFr�geNo
			// 
			this->lblFr�geNo->AutoSize = true;
			this->lblFr�geNo->Location = System::Drawing::Point(266, 12);
			this->lblFr�geNo->Name = L"lblFr�geNo";
			this->lblFr�geNo->Size = System::Drawing::Size(46, 13);
			this->lblFr�geNo->TabIndex = 10;
			this->lblFr�geNo->Text = L"Fr�ga 1:";
			// 
			// txtSvar1
			// 
			this->txtSvar1->Location = System::Drawing::Point(310, 176);
			this->txtSvar1->Name = L"txtSvar1";
			this->txtSvar1->Size = System::Drawing::Size(437, 20);
			this->txtSvar1->TabIndex = 11;
			// 
			// txtSvar2
			// 
			this->txtSvar2->Location = System::Drawing::Point(310, 202);
			this->txtSvar2->Name = L"txtSvar2";
			this->txtSvar2->Size = System::Drawing::Size(437, 20);
			this->txtSvar2->TabIndex = 12;
			// 
			// txtSvar3
			// 
			this->txtSvar3->Location = System::Drawing::Point(310, 228);
			this->txtSvar3->Name = L"txtSvar3";
			this->txtSvar3->Size = System::Drawing::Size(437, 20);
			this->txtSvar3->TabIndex = 13;
			// 
			// txtSvar4
			// 
			this->txtSvar4->Location = System::Drawing::Point(310, 254);
			this->txtSvar4->Name = L"txtSvar4";
			this->txtSvar4->Size = System::Drawing::Size(437, 20);
			this->txtSvar4->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(263, 179);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Svar 1:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(263, 205);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Svar 2:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(263, 231);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Svar 3:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(263, 257);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Svar 4:";
			// 
			// radSvar1
			// 
			this->radSvar1->AutoSize = true;
			this->radSvar1->Checked = true;
			this->radSvar1->Location = System::Drawing::Point(753, 177);
			this->radSvar1->Name = L"radSvar1";
			this->radSvar1->Size = System::Drawing::Size(68, 17);
			this->radSvar1->TabIndex = 19;
			this->radSvar1->TabStop = true;
			this->radSvar1->Text = L"R�tt svar";
			this->radSvar1->UseVisualStyleBackColor = true;
			// 
			// radSvar2
			// 
			this->radSvar2->AutoSize = true;
			this->radSvar2->Location = System::Drawing::Point(753, 203);
			this->radSvar2->Name = L"radSvar2";
			this->radSvar2->Size = System::Drawing::Size(68, 17);
			this->radSvar2->TabIndex = 20;
			this->radSvar2->Text = L"R�tt svar";
			this->radSvar2->UseVisualStyleBackColor = true;
			// 
			// radSvar3
			// 
			this->radSvar3->AutoSize = true;
			this->radSvar3->Location = System::Drawing::Point(753, 229);
			this->radSvar3->Name = L"radSvar3";
			this->radSvar3->Size = System::Drawing::Size(68, 17);
			this->radSvar3->TabIndex = 21;
			this->radSvar3->TabStop = true;
			this->radSvar3->Text = L"R�tt svar";
			this->radSvar3->UseVisualStyleBackColor = true;
			// 
			// radSvar4
			// 
			this->radSvar4->AutoSize = true;
			this->radSvar4->Location = System::Drawing::Point(753, 255);
			this->radSvar4->Name = L"radSvar4";
			this->radSvar4->Size = System::Drawing::Size(68, 17);
			this->radSvar4->TabIndex = 22;
			this->radSvar4->Text = L"R�tt svar";
			this->radSvar4->UseVisualStyleBackColor = true;
			this->radSvar4->CheckedChanged += gcnew System::EventHandler(this, &SkapaTentaForm::radioButton4_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(266, 280);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 23;
			this->button1->Text = L"N�sta fr�ga";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SkapaTentaForm::button1_Click);
			// 
			// btnKlar
			// 
			this->btnKlar->Location = System::Drawing::Point(746, 280);
			this->btnKlar->Name = L"btnKlar";
			this->btnKlar->Size = System::Drawing::Size(75, 23);
			this->btnKlar->TabIndex = 24;
			this->btnKlar->Text = L"Klar";
			this->btnKlar->UseVisualStyleBackColor = true;
			this->btnKlar->Click += gcnew System::EventHandler(this, &SkapaTentaForm::btnKlar_Click);
			// 
			// SkapaTentaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(833, 311);
			this->Controls->Add(this->btnKlar);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radSvar4);
			this->Controls->Add(this->radSvar3);
			this->Controls->Add(this->radSvar2);
			this->Controls->Add(this->radSvar1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtSvar4);
			this->Controls->Add(this->txtSvar3);
			this->Controls->Add(this->txtSvar2);
			this->Controls->Add(this->txtSvar1);
			this->Controls->Add(this->lblFr�geNo);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->txtFr�ga);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"SkapaTentaForm";
			this->Text = L"SkapaTentaForm";
			this->Load += gcnew System::EventHandler(this, &SkapaTentaForm::SkapaTentaForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (txtID->Text == ""
				 || txt�mne->Text == ""
				 || txtKurskod->Text == ""
				 || txtPo�ng->Text == ""
				 || txtFr�ga->Text == ""
				 || txtSvar1->Text == ""
				 || txtSvar2->Text == ""
				 || txtSvar3->Text == ""
				 || txtSvar4->Text == "")
			 {
				 MessageBox::Show("Fyll i allt!");

				 return;
			 }

			 if (_fr�geNo == 1)
			 {
				 txtID->Enabled = false;
				 txtKurskod->Enabled = false;
				 txtPo�ng->Enabled = false;
				 txt�mne->Enabled = false;

				 _examensID = txtID->Text;
			 }


			if (_fr�geNo >= 250)
			{
				// KLAR NU!
			}

			sparaFr�ga();

			 txtFr�ga->Clear();
			 txtSvar1->Clear();
			 txtSvar2->Clear();
			 txtSvar3->Clear();
			 txtSvar4->Clear();

			 radSvar1->Checked = true;

			_fr�geNo++;
			 lblFr�geNo->Text = "Fr�ga " + _fr�geNo + ":";
		 }
private: System::Void SkapaTentaForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 _fr�geNo = 1;
		 }

		 void sparaFr�ga()
		 {
			
			 int r�ttSvar = 0;

			 if (radSvar1->Checked)
				 r�ttSvar = 1;
			 else if (radSvar2->Checked)
				r�ttSvar = 2;
			 else if (radSvar3->Checked)
				r�ttSvar = 3;
			 else if (radSvar4->Checked)
				r�ttSvar = 4;

			 array<String^>^ svar = gcnew array<String^>(4);
			 
			 svar[0] = txtSvar1->Text;
			 svar[1] = txtSvar2->Text;
			 svar[2] = txtSvar3->Text;
			 svar[3] = txtSvar4->Text;

			 Fr�ga ^ fr�ga = gcnew Fr�ga(_cmd, _fr�geNo, _examensID, txtFr�ga->Text, svar, r�ttSvar);

			 _fr�gor[_fr�geNo-1] = fr�ga;
		 }

private: System::Void btnKlar_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (Forms::DialogResult::Yes == MessageBox::Show("�r du klar med tentamen?", "Klar?", MessageBoxButtons::YesNo, MessageBoxIcon::Question ))
			 {
				 sparaFr�ga();
				 for (int i = 0; i < _fr�geNo; i++)
				 {
					 _fr�gor[i]->addToDb();
				 }

				_cmd->CommandText = "INSERT INTO [dbo].[tentamen] VALUES (@examensID ,@�mne, @po�ng, @kurskod)";
				_cmd->Parameters->Add(gcnew SqlParameter("@examensID", SqlDbType::Char));
				_cmd->Parameters["@examensID"]->Value = _examensID;
				_cmd->Parameters->Add(gcnew SqlParameter("@�mne", SqlDbType::Char));
				_cmd->Parameters["@�mne"]->Value = txt�mne->Text;
				_cmd->Parameters->Add(gcnew SqlParameter("@po�ng", SqlDbType::Int));
				_cmd->Parameters["@po�ng"]->Value = txtPo�ng->Text;
				_cmd->Parameters->Add(gcnew SqlParameter("@kurskod", SqlDbType::Char));
				_cmd->Parameters["@kurskod"]->Value = txtKurskod->Text;
				_cmd->ExecuteNonQuery();
				_cmd->Parameters->Clear();
			 }
		 }
};
}
