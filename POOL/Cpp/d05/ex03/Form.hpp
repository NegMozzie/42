/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:25:59 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:25:59 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Form {

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade too High";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade too low";
        }
    };

    Form(std::string name, short sign, short execute);

    Form(Form &src);

    virtual ~Form(void);

    Form &operator=(Form &src);

    bool getValidated(void) const;

    short getGradeSign(void) const;

    std::string getName(void) const;

    short getGradeExecute(void) const;

    void beSigned(Bureaucrat &src);

    virtual void execute(const Bureaucrat &executor) const = 0;

private:
    bool validated;
    const std::string name;
    const short gradeSign;
    const short gradeExecute;

    Form(void);

};

std::ostream &operator<<(std::ostream &o, Form &rhs);


#else
class Form;
#endif