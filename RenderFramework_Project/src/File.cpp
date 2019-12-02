//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
//----------------------------------------------------------------------------- 

#include <assert.h>
#include "Framework.h"

#include "File.h"

#define STUB_PLEASE_REPLACE(x) ((void *)x)
#define STUB_PLEASE_REPLACE_2(x) ((void)x)

bool File::IsHandleValid(File::Handle fh) noexcept
{
	DWORD flag;
	return GetHandleInformation(fh, &flag) != 0;
}

File::Error File::Open( File::Handle &fh, const char * const fileName, File::Mode mode ) noexcept
{
	File::Error err = File::Error::SUCCESS;
	if (IsHandleValid(fh)||fileName == nullptr) {//Reopen
		err = File::Error::OPEN_FAIL;
	}
	else {
		switch (mode)
		{
		case File::Mode::READ:
			fh = CreateFileA(fileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_DIRECTORY, NULL);
			break;
		case File::Mode::WRITE:
			fh = CreateFileA(fileName, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_DIRECTORY, NULL);
			break;
		case File::Mode::READ_WRITE:
			fh = CreateFileA(fileName, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_DIRECTORY, NULL);
			break;
		default:
			fh = CreateFileA(fileName, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_DIRECTORY, NULL);
			break;
		}
	}
	
	if (!IsHandleValid(fh)) {
		err = File::Error::OPEN_FAIL;
	}
	else {

	}

	return	err;
}

File::Error File::Close( const File::Handle fh ) noexcept
{
	File::Error err = File::Error::SUCCESS;
	if (!IsHandleValid(fh)) {
		err = File::Error::CLOSE_FAIL;
	}
	else if (CloseHandle(fh) == 0) {
		err = File::Error::CLOSE_FAIL;
	}
	
	return 	err;
}

File::Error File::Write( File::Handle fh, const void * const buffer, const DWORD inSize ) noexcept
{
	File::Error err = File::Error::SUCCESS;
	if (!IsHandleValid(fh)) {
		err = File::Error::WRITE_FAIL;
	}
	else {
		DWORD byteWritten;
		if (WriteFile(fh, buffer, inSize, &byteWritten, NULL) == 0) {
			err = File::Error::WRITE_FAIL;
		}
	}
	

	return err;
}

File::Error File::Read( File::Handle fh,  void * const buffer, const DWORD inSize ) noexcept
{
	File::Error err = File::Error::SUCCESS;
	if (!IsHandleValid(fh)) {
		err = File::Error::READ_FAIL;
	}
	else {
		DWORD byteWritten;
		if (ReadFile(fh, buffer, inSize, &byteWritten, NULL) == 0) {
			err = File::Error::READ_FAIL;
		}
	}
	

	return err;
}

File::Error File::Seek( File::Handle fh, File::Location location, int offset ) noexcept
{
	File::Error err = File::Error::SUCCESS;
	if (!IsHandleValid(fh)) {
		err = File::Error::SEEK_FAIL;
	}
	else {
		DWORD moveMethod = 0;
		switch (location)
		{
		case File::Location::BEGIN:
			moveMethod = FILE_BEGIN;
			break;
		case File::Location::CURRENT:
			moveMethod = FILE_CURRENT;
			break;
		case File::Location::END:
			moveMethod = FILE_END;
			break;
		default:
			break;
		}
		if (SetFilePointer(fh, offset, NULL, moveMethod) == INVALID_SET_FILE_POINTER) {
			err = File::Error::SEEK_FAIL;
		}
	}


	return err;
}

File::Error File::Tell( File::Handle fh, DWORD &offset ) noexcept
{
	File::Error err = File::Error::SUCCESS;
	if (!IsHandleValid(fh)) {
		err = File::Error::TELL_FAIL;
	}
	else {

		DWORD result = SetFilePointer(fh, 0, NULL, FILE_CURRENT);
		if (result == INVALID_SET_FILE_POINTER) {
			err = File::Error::TELL_FAIL;
		}
		else {
			offset = result;
		}
	}


	return err;
}

File::Error File::Flush( File::Handle fh ) noexcept
{
	File::Error err = File::Error::SUCCESS;
	if (!IsHandleValid(fh)) {
		err = File::Error::FLUSH_FAIL;
	}
	else {
		if (FlushFileBuffers(fh) == 0) {
			err = File::Error::FLUSH_FAIL;
		}
	}


	return err;
}

// ---  End of File ---------------
