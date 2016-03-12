#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

#include <compat/tabos.h>
#include <user/sys_fio.h>

sint32 touch( char *pName )
{
    int nHandle;

    nHandle = Open( pName, O_RDONLY );

    if( nHandle >= 0 )
    {
        Close( nHandle );
        Print( "file already exists\n" );
        return -EFAIL;
    }
    Close( nHandle );

    nHandle = Create( pName, 0666 );
    if ( nHandle > 0 )
    {
        Close( nHandle );
        return ESUCCESS;
    }

    Print( "touch failed\n" );
    return -EFAIL;
}

int main( int argc, char **argv )
{
    int nIndex;

    if ( argc == 1 ) {
        Print( "Syntax: touch [FILE] ...\n" );
        return -EFAIL;
    }

    for ( nIndex = 1; nIndex < argc; nIndex++ )
    {
        touch( argv[ nIndex ] );
    }

    return ESUCCESS;
}

