// -*- coding: utf-8; indent-tabs-mode: nil; tab-width: 4; c-basic-offset: 4; -*-

/*
* functional++/noncopyable.hpp
*
* This class prevents the copying any class derived from this one
*
* Example:
* class T: public functional::noncopyable {
*    // ...
* };
*
* @author: Alexander Guinness
* @version: 0.0.1
* @license: MIT
* @date: 25/11/2012 21:05 PM
*/
#ifndef __FUNCTIONAL_PP_NOCOPYABLE__
#define __FUNCTIONAL_PP_NOCOPYABLE__

namespace functional
{
	class noncopyable
	{
		private:
			noncopyable(noncopyable const &) = delete;
			noncopyable const &operator=(noncopyable const &) = delete;

		protected:
			 noncopyable() {};
			~noncopyable() {};
	};
}

#endif
