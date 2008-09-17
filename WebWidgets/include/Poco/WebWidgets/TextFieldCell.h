//
// TextFieldCell.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/TextFieldCell.h#7 $
//
// Library: WebWidgets
// Package: Controls
// Module:  TextFieldCell
//
// Definition of the TextFieldCell class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef WebWidgets_TextFieldCell_INCLUDED
#define WebWidgets_TextFieldCell_INCLUDED


#include "Poco/WebWidgets/Cell.h"
#include "Poco/WebWidgets/Delegate.h"
#include "Poco/FIFOEvent.h"


namespace Poco {
namespace WebWidgets {


class WebWidgets_API TextFieldCell: public Cell
	/// A Cell for a TextField.
{
public:
	typedef Poco::AutoPtr<TextFieldCell> Ptr;
	
	static const std::string FIELD_OLDVAL;
	static const std::string FIELD_NEWVAL;
	static const std::string EV_TEXTCHANGED;
	
	struct WebWidgets_API ValueChange
		/// Data sent with a textChanged event. 
	{
		Formatter::Ptr pFormatter;
		const Poco::Any oldValue;
		const Poco::Any newValue;
		ValueChange(Formatter::Ptr pFormatter, const Poco::Any& oldValue, const Poco::Any& newValue);
		bool differ() const;
			/// Returns true if oldValue and newValue are different
	};

	FIFOEvent<ValueChange> textChanged;

	TextFieldCell(View* pOwner);
		/// Creates a TextFieldCell.

	void setPlaceHolder(const std::string& text);
		/// Sets the TextField's placeholder content.

	const std::string& getPlaceHolder() const;
		/// Returns the TextField's placeholder content.	

	void setMaxLength(int length);
		/// Sets the maximum length of the field.
		/// Specify -1 for unlimited.

	int getMaxLength() const;
		/// Returns the maximum length of the text field, or -1
		/// if the length is unlimited.

	// Cell
	void handleForm(const std::string& field, const std::string& value);
	
	bool serializeJSON(std::ostream& out, const std::string& name);

protected:
	~TextFieldCell();
		/// Destroys the TextFieldCell.

	TextFieldCell(View* pOwner, const std::type_info& type);
		/// Creates a TextFieldCell.

private:
	std::string _placeHolder;
	int         _maxLength;
};


//
// inlines
//
inline const std::string& TextFieldCell::getPlaceHolder() const
{
	return _placeHolder;
}


inline int TextFieldCell::getMaxLength() const
{
	return _maxLength;
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_TextFieldCell_INCLUDED
