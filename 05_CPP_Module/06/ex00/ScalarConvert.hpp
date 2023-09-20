/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:20:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/20 18:56:15 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <string>

class	ScalarConvert
{
	private:
		/* data */
	public:
		ScalarConvert();
		ScalarConvert( const ScalarConvert &sc );
		~ScalarConvert();

		ScalarConvert&	operator=( const ScalarConvert &sc );

		static void	convert( std::string str );
};

/* Static Class */
// 인스턴스화 할 수 없는 클래스
// 클래스의 모든 멤버가 static 멤버이다.
// 정적 클래스는 전역 변수와 유사한 역할을 수행하며
// 정적 변수와 마찬가지로 프로그램이 실행될 때 클래스 멤버가 초기화된다.

#endif
