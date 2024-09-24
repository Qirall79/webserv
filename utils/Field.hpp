/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbelfatm <wbelfatm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:40:14 by wbelfatm          #+#    #+#             */
/*   Updated: 2024/09/24 09:38:15 by wbelfatm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_HPP

# define FIELD_HPP

#include <iostream>
#include <vector>

class Field {
    private:
        std::string name;
        std::vector<std::string> values;

    public:
        Field( void );

        void addValue( std::string );
        std::vector<std::string> getValues( void );
};

#endif