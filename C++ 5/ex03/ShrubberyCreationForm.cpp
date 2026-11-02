/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:51:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/16 12:53:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// =================== (Cons/Des)tructors ===================

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery", "Unknown", 137, 145)
{
	std::cout << YELLOW << "	Some seeds bought\n" << WHITE;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery", target, 137, 145)
{
	std::cout << "	" << target << YELLOW << " seeds bought\n" << WHITE;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm("Shrubbery", other.getTarget(), 137, 145)
{
	std::cout << "	" << other.getTarget() << YELLOW << " seeds duplicated\n" << WHITE;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "	" << getTarget() << YELLOW << " seeds burned\n" << WHITE;
}

// =================== Operators ===================

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (&other != this)
		std::cout << MAGENTA << "Shrubbery forms cannot be rewritten\n" << WHITE;
	return *this;
}

// =================== Protected ===================

void ShrubberyCreationForm::create(void) const
{
	std::string trees[3];

	trees[0] =	"                                               .\n"
				"                                   .         ;\n"
				"      .              .              ;%     ;;\n"
				"        ,           ,                :;%  %;\n"
				"         :         ;                   :;%;'     .,\n"
				",.        %;     %;            ;        %;'    ,;\n"
				"  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
				"   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
				"    ;%;      %;        ;%;        % ;%;  ,%;'\n"
				"    `%;.     ;%;     %;'         `;%%;.%;'\n"
				"      `:;%.    ;%%. %@;        %; ;@%;%'\n"
				"         `:%;.  :;bd%;          %;@%;'\n"
				"           `@%:.  :;%.         ;@@%;'\n"
				"             `@%.  `;@%.      ;@@%;\n"
				"               `@%%. `@%%    ;@@%;\n"
				"                 ;@%. :@%%  %@@%;\n"
				"                   %@bd%%%bd%%:;\n"
				"                     #@%%%%%:;;\n"
				"                     %@@%%%::;\n"
				"                     %@@@%(o);  . '\n"
				"                     %@@@o%;:(.,'\n"
				"                 `.. %@@@o%::;\n"
				"                    `)@@@o%::;\n"
				"                     %@@(o)::;\n"
				"                    .%@@@@%::;\n"
				"                    ;%@@@@%::;.\n"
				"                   ;%@@@@%%:;;;.\n"
				"               ...;%@@@@@%%:;;;;,..\n"
				"------------------------------------------------";

	trees[1] =	"      __\n"
				"      ><<\n"
				"     >>><<<\n"
				"      >%%<<<\n"
				"     >>%%\\%<<\n"
				"      >>%|%<<<\n"
				"    >>>%%|%<<<\n"
				"      >>%|%%<<\n"
				"    >` >%|%%<<<\n"
				"       >>|%%<<<\n"
				"        >|<<-<<<<\n"
				"         ||  `<<\n"
				"       >-||<\n"
				"         ||-<\n"
				"         ||--<<\n"
				"      >--||\n"
				"         ||\n"
				"         ||-\n"
				"         ||\n"
				"         ||\n"
				"         ||-\n"
				"         ||-\n"
				"         ||\n"
				"         ||-\n"
				"------------------------------------------------";

	trees[2] =	"          ; ; ;\n"
				"       ;        ;  ;     ;;    ;\n"
				"    ;                 ;         ;  ;\n"
				"                   ;                ;;\n"
				"   ;          ;            ;              ;\n"
				"   ;            ';,        ;               ;\n"
				"   ;              'b      *\n"
				"    ;              '$    ;;                ;;\n"
				"   ;    ;           $:   ;:               ;\n"
				" ;;      ;  ;;      *;  @):        ;   ; ;\n"
				"              ;     :@,@):   ,;**:'   ;\n"
				"  ;      ;,         :@@*: ;;**'      ;   ;\n"
				"           ';o;    ;:(@';@*'  ;\n"
				"   ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n"
				"              ,p$q8,:@)'  ;p*'      ;\n"
				"       ;     '  ; '@@Pp@@*'    ;  ;\n"
				"        ;  ; ;;    Y7'.'     ;  ;\n"
				"                  :@):.\n"
				"                 .:@:'.\n"
				"               .::(@:.\n"
				"------------------------------------------------";
	std::ofstream outfile((getTarget() + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cout << RED "Failed to create outfile\n" << WHITE;
		return ;
	}
	outfile << trees[rand() % 3] << std::endl;
}

