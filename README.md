# braysite

This is some PHP code I put together to do the website for Bray Wanderes FC.

Much of the code could in principle be used for other websites.   However, the code was originally written in 2001 or 2002, in
PHP, and not done as rigorously as it should have been.    Plus it was written for PHP 3 - so although it works under PHP5,
it's still pretty hideous.

If you do deploy this setup, here's a few pointers:

The .inc files in the main directory generate the content for specific page.   They are setup by symlinking the .php file of
the same name to template.html.   For example:

news.inc needs news.php to be linked to template.html

template.html contains PHP code to call the .inc file based on what filename it is accessed under.

You need access to a MySQL Database.    Rename functions-SAMPLE.inc to functions.inc and add the MySQL server details into the 
file to connect.

The embedded code uses the <? short version to embed PHP code.   This may need a tweak to the php.ini file to get this to 
work properly
