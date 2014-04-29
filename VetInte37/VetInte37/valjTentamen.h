#pragma once
#include "stdafx.h"
#include "skrivTentaForm.h"

namespace Forms {

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
	/// Summary for väljTentamen
	/// </summary>
	public ref class väljTentamen : public System::Windows::Forms::Form
	{
	public:

		DbCommand ^ _cmd;

		väljTentamen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void setCmd(DbCommand ^ cmd)
		{
			_cmd = cmd;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~väljTentamen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbTents;
	protected: 
	private: System::Windows::Forms::Button^  btnChoose;

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
			this->lbTents = (gcnew System::Windows::Forms::ListBox());
			this->btnChoose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbTents
			// 
			this->lbTents->FormattingEnabled = true;
			this->lbTents->Location = System::Drawing::Point(12, 12);
			this->lbTents->Name = L"lbTents";
			this->lbTents->Size = System::Drawing::Size(582, 277);
			this->lbTents->TabIndex = 0;
			// 
			// btnChoose
			// 
			this->btnChoose->Location = System::Drawing::Point(519, 295);
			this->btnChoose->Name = L"btnChoose";
			this->btnChoose->Size = System::Drawing::Size(75, 23);
			this->btnChoose->TabIndex = 1;
			this->btnChoose->Text = L"Välj";
			this->btnChoose->UseVisualStyleBackColor = true;
			this->btnChoose->Click += gcnew System::EventHandler(this, &väljTentamen::btnChoose_Click);
			// 
			// väljTentamen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(606, 326);
			this->Controls->Add(this->btnChoose);
			this->Controls->Add(this->lbTents);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"väljTentamen";
			this->Text = L"väljTentamen";
			this->Load += gcnew System::EventHandler(this, &väljTentamen::väljTentamen_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnChoose_Click(System::Object^  sender, System::EventArgs^  e) {

				 skrivTentaForm ^stForm = gcnew skrivTentaForm();

				 String ^ examenString = lbTents->SelectedItem->ToString();
				 
				 stForm->setVars(_cmd, examenString);

				 stForm->ShowDialog();
			 }




	private: System::Void väljTentamen_Load(System::Object^  sender, System::EventArgs^  e) {
				_cmd->CommandText="SELECT * FROM [dbo].[tentamen]";
				DbDataReader^ reader = _cmd->ExecuteReader();
				
				
				String ^examensID = "";
				String ^ämne = "";
				int poäng = 0;
				String ^kurskod = "";

				while (reader->Read())
				{
					examensID = reader->GetString(0)->Trim();
					ämne = reader->GetString(1)->Trim();
					poäng = reader->GetInt32(2);
					kurskod= reader->GetString(3)->Trim();

					lbTents->Items->Add(examensID + " - " + ämne + " - " + poäng + " - " + kurskod);
				}

				lbTents->SelectedIndex = 0;

				reader->Close();
			 }
	};
}
