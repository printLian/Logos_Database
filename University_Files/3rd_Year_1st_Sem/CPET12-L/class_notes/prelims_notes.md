PRELIMS NOTES

 ACCESSING A WEBSITE (FLOW)
1. URL- You request a webpage by accessing a URL. URL contains information about a specific html document on a web server in the internet. 
2. HTTP Request- Browser sends an https request to that web server and asks for the page (html file). 
3. HTTP Response- Web server looks for the requested  files on its own server.

Notes about HTTPS Response:
- If page cannot be found in the web server, web server throws a "404 Not Found" message.
- If page and files are found, requested file is returned to the browser of the user. 
- Static Website: Fixed html file with fixed content.
- Dynamic Website: May kasama nang backend.

4. Parsing- Once the requested file is returned to the browser through a HTTP Response, the broswer of the user parses the html file. Individual elements na labas sa html file such as images are requested again to be retrieved from the web server and returned back to the browser.

Definition of Terms

HTML- The markup language used to describe web content

W3C — The organization that monitors web technologies

CERN — The particle physics lab where the web was born

CSS — The language used to specify how web content looks

HTTPS — A protocol for transferring web documents on the internet securely

IP — Internet Protocol

URL — The location of a web document or resource

NCSA — Home of Mosaic, the first graphical browser

DNS — Matches domain names with numeric IP addresses

FTP — A protocol for file transfer

BIG CONCEPTS
- refers to the situations and factors that a web designer needs to take into account when making their website.

1. Multitude of Devices- The release of various smartphones, screen resolutions and sizes of screens should be taken into account to create and accessible and functional web page.
2. Web Standards- Programmmers of webiste should adhere to the standards set by the World Wide Web Consortium (W3C) so that websites would appear consistent across all modern browsers and devices.
3. Progressive Enhancement- Strategy that ensures websites can work on all browsers regardless of the capability.

    a. Authoring Strategy- Writing clean html code on most known devices and broswers.
    b. Styling Strategy- Do CSS progressively as older browsers ignore rules they don't understand then add incrementaly.
    c. Scripting Strategy- Ensure basic site functionality even if java script is disabled.

4. Responsive Web Design (RWD)- Utilization of HTML and CSS layouts so that a web page will adjust its size depending on difference screen sizes and device types.
5. Accessibility- Website is ensured to be utilized by everyone regardless of capability, device, browser utilized or other factors. Websites should be accessed through a variety of methodologies, foot pedals, joysticks, braille displays and more.

    CATEGORIES OF DISABILITIES AFFECTING WEB INTERACTION
    a. Vision Impairment- People with low or no vision may use assistive devices to access websites well.
    b. Mobility Impairment- People who are limited or no use to their hands should be able to utilize assistive devices such as foot pedal, voice commands and more.
    c. Auditory Impairment- People who have limited to no hearing capaility should be given alternatives to access a website such as transcripts or captions.
    b. Cognitive Ipairment- Users with limitations with regards to reading comprehension, problem solving and attention limitations benefit when sites are designed in a simple and clear manner.

    ACCESSIBILITY STANDARDS 
    a. W3C's Web Accessiblitry Initiative (WAI)
    b. Web Content Accesibility Guidelins (WCAG)
    c. WAI-ARIA (Accessible Rich Internet Applications)


6. Site Performance- refers tro how quickly a website loads and responds. This directly affects user satisfaction and even business revenue.

    KEY OPTIMIZATION PRACTICES
    - Optimize images to reduce file size
    - Streamline HTML by reducing nesting
    - Limit JavaScript Use
    - Reduce HTTPS Requests.
    - Utilize Network tool in a given browser's Developer Tools to view all server requests.

ANATOMY OF HTML ELEMENT
- Element- building blocks of html that define the structure and meaning of contents.

<h1>Title</h1>

- The whole thing based on the example above is called the element. The one that defines it (<h1>) is called a tag. We have the opening tag (<h1>) and the closing tag (</h1>). The actual content (Title) is called the content.
- Tags are not case sensitive. 

BASIC HTML SETUP

1. <!DOCTYPE html>
2. <html lang="en">

3.    <head>
4.    <meta charset="utf-8">
5.    <title>Title Here</title>
6.    </head>

7.    <body>
8.     <!-- Page Content goes here -->
9.    </body>
10. </html>

1. Document Type Declaration- Lets modern browsers know that the document is an html file.
2. Root Element- Contains all elements in the html document.
               - lang is an attribute that specifies what language the document is in.
               - en is the element that says that the html document is in english,
3. Head- Element that is not part of the actual content of the html document.
4. meta- element that specifies the characters to be utilized by the html document. utf-8 means unicode.
5. Title- Content to be shown on the tab browser once this html file is accessed.
6. body- everything we want to show up in the browser window. 

FURTHER IDENTIFYING HTML ELEMENTS
- HTML Markups- Add structure to the content of a given page.
- Semantic Markups- choosing HTML elements that accurately describe the purpose of the content.
- CSS- should be utilized when handling the appearance of elements.
- Document Object Model (DOM)- Model layout commonly seen in html about elements in a nested form.
- By default, elements display themselves by vertical block elements taking up the whole width of a given browser. That means if you set the background of h1 to red in CSS, you would see a whole red background of h1 spanning the totality of the width of the browser.

VOID ELEMENTS
- html elements that do not have closing tags and rather displaying text contents, they do other visual structuring contents in the body.

Example of Void Elements:
<img>- embeds and image
<br>- line break
<hr>- Horizontal Rule
<meta>- document information

ATTRIBUTES
- instructions that modify or clarify an element.
- syntax is as follows:
<tag attributeName="value">
- Multiple attributes are separated by space.
    
VALIDATING DOCUMENTS
- Validation- refers to checking if your html and CSS documents adhere to rules and standards for web design.
- Validators- Tools that automatically detect HTML/CSS errors. Code editors and browsers usually have validators with them. Furthermore, you could utilize Nu HTML Checker which is an online tool validator.

HTML SEMANTIC ELEMENTS

PARAGRAPH
<p></p>
- displays content automatically in new line

HEADINGS
<h1></h1> -> <h6></h6>
- Headings. Up to 6

THEMATIC BREAKS (HORIZONTAL RULE)
<hr>
- Void element that puts a logical divider 

LISTS
- Self-Explanatory. Has three types in html.

	a. Unordered Lists
	<ul>
		<li></li>
	</ul>
	- Shows list elements in an unordered manner and presents them in bullet form.
	- Only list elements are permitted in an unordered list.

	b. Ordered Lists
	<ol>
		<li></li>
	</ol> 
	- Same as unordered lists but instead of bullets, numbers.
	- If you want the list to start other than what, then you set the appropriate attribute and value for it which is:
	<ol start="17">

	c. Description Lists
	<dl>
		<dt></dt>
		<dd></dd>
	</dl>
	- Pair of label (<dt>) and its respective value or description (<dd>)

BLOCK QUOTE (LONG QUOTATIONS)
<blockquote></blockquote>
- Utilized for quotations or testimonials from other people.

Preformat
<pre></pre>
- Allows white space.

ORGANIZING PAGE CONTENT
- Do take note that essentially, none of these elements are only good for organizing your webpage and to help the browser read the web page better. Each of these elements have no specific requirement to be semantically utilized and one could use them however they like.

MAIN
<main></main>
- Main content of a given page. Don't nest other elements in there such as article, header, or footer as the main element would be rendered null.


HEADER
<header></header>
- Usually utilized for introductory stuff on your webpage.

FOOTERS
<footer></footer>
- Self-explanatory.

SECTION
<section></section>
- Way to divide long webpages into sections

ARTICLE
<article></article>
- Utilized for stand alone or reusing uses.

ASIDE
<aside></aside>
- Sidebar. Presents elements on the side.

NAVIGATION
<nav></nav>
- Utilized for navigation (has usually anchor elements within it).

SEARCH 
<search></search>
- Element for searching certain content in a given page. 

ADDRESS
<address></address>
- Usually an element where the contact information are presented. 

TEXT-LEVEL ELEMENTS
- Elements that are usually placed within content and does nothing to how it is presented when loaded into a web page unless specified under CSS.

EMPHASIS
<em></em>
- Focuses on a given content.
- Emphasized contents is italicized.

STRONG (IMPORTANT TEXT)
<strong></strong>
- Same as emphasis but selected content is in bold.

BOLD
<b></b>

ITALIC
<i></i>

STRIKETHROUGH
<s></s>

UNDERLINE
<u></u>

SMALL
<small></small>
- Makes the font-size smaller.

ABBREVIATION
<abbr title="(Word you want abbreviated)">(Abbreviated word)</abbr>

CITATIONS
<cite></cite>
- Defaults in italic.

DEFINE
<dfn></dfn>
- Same as Citation that italicizes a selected content. Usually utilize for highlighting first instance a given word is used in the web document.

SUBSCRIPT
<sub></sub>

SUPERSCRIPT
<sup></sup>

HIGHLIGHTED TEXT (MARK)
<mark></mark>
- highlights specified content to yellow by default. Can be utilized in conjunction to the search element. 

TIMES AND DATES
- Has different attributes in setting up the dates and times you want to present on your web page.
- The following is the format:

<time datetime="YYYY-MM-DDThh:mm:ss.ddd+-hh:mm">DateTime Content Format	</void element>
- Do take note that the separation between date and time is through T without spaces. For the separation of time and time zone, + or -.
- Simply a time and date. Does not update.

DATA
<data></data>
- Has attribute value and is utilized just like time. For example:

<data value="12">Twelve</data>

INSERTED and DELETED
<ins></ins>
<del></del>
- Utilized to tell changes in a webpage.

WORD BREAK
<wbr></wbr>
- Browser automatically handles long words to split them properly when they are too long.

DIV
<div></div>
- Another way to group elements together.
- can be put into identifiers to separate multiple divs with that attribute class.


SPAN
<span></span>
- Utilized to take in a specific content to style it.

ATTRIBUTES

ID
<(elements) id="(id name)"></(elements)>
- utilized as an identification. Can be used in various grouping elements. For example:

<div id="100df7">hello</div>

CLASS
<(elements) class="(class name)"></(elements)>

ROLE
<(elements) role="(role name)"></(elements)>
- predefined parameters that helps web browser identify the role or purpose of each element in an html document.
- Has different values for defining elements: Banner, main, navigation, button, menu, slider, heading, article, alert, status, timer, progressbar, table and so on.


ADDING LINKS

ANCHOR
<a href="(link)">content</a>
- links you to another website or another page within your directory.
- the href attribute (hypertext reference) makes this possible by utilizing an address called URL to link an anchored element to another page. There are two types of URLs

	1. Absolute URL- Provides full URL of the document including protocol.
	2. Relative URL- File path name.
- When using anchor relative URL and the document you need is on a higher directory:
	<a href="../../index.html">(content)</a>
- Alternatively, you could start from the root directory and incrememntaly go each directory until you get to your desired document.
- src attribute in images works the same.

LINKING TO A DOCUMENT FRAGMENT
- refers to redirecting or linking a certain elements to another element that is within the page.
	
	Step 1: Make a fragment identifier- Use the id attribute to the element you want to be fragmented.
	Step 2: Use the anchor element with the href attribute and as its value, input the value of the id attribute of the element you fragmented. Do not forget to add # in between the starting quotation for the value of attribute href and the name of the id fragment. For example

	<div id="hello">hello</div>
	<a href="#hello">Link</a>

LINKING TO A DOCUMENT FRAGMENT OF ANOTHER HTML FILE
Step 1: Make a fragment identifier- Use the id attribute to the element you want to be fragmented.
Step 2: Use the anchor element with the href attribute and as its value, input directory or file name of the document then input the value of the id attribute of the element you fragmented. Do not forget to add # in between the starting quotation for the value of attribute href and the name of the id fragment. For example

	<div id="hello">hello</div>
	<a href="index.html#hello">Link</a>

TARGETING A NEW BROWSER WINDOW 
<a href="(link or file path" target="(either _blank or new name of tab">content</a>

MAIL LINKS
<a href="mailto:(email)">content</a>

TELEPHONE LINKS
<a href="tel:(+country number)(number with divisions)">content</a>

IMG
loading attribute in img apart from src

loading can have two values in img, lazy and eager. Lazy means images to be viewed later on in the document will be loaded later so that needed images for viewing would be prioritzed, using the eager value of the loading attribute will do otherwise.

SVG
- images that are made purely from elements and attributes within html making them more versatile when it comes to resizing withou loss in quality.
- SVGs can be utilized in img src or its full code can be implemented in an html document so that individual elements in the svg image can be styled using css or animated using js

PICTURE
- there are new image file formats with better compression. With that, the picture elements with elements and attributes within it give the browser alternatives in the form of these new image file formats before loading older image file formats if the browser does not support it.

<picture>
     <source type="image/avif" srcset="pizza.avif">
     <source type="image/webp" srcset="pizza.webp">
     <img src="pizza.jpg" alt="Image cannot be loaded">
</picture>

TABLES
<table>
   <tr>
      <th>column1</th>
      <th>column2</th>
   </tr>

   <tr>
       <td>Data1</td>
       <td>Data2</td>
   </tr>
</table>

tr= table row
th= table header
td= table data

COLUMN AND ROW SPAN ATTRIBUTES
- merge cell in the form of row and column

Column Span
<table>
   <tr>
   <th colspan="2">Merge</th>
</tr>

   <tr>
       <td>Data1</td>
       <td>Data2</td>
   </tr>
</table>

Row span
<table>
   <tr>
      <th rowspan="2">column1</th>
     
   </tr>

   <tr>
       <td>Data1</td>
       <td>Data2</td>
   </tr>
</table>

CAPTION FOR TABLES


<table>
<caption>Caption</caption>
   <tr>
      <th>column1</th>
      <th>column2</th>
   </tr>

   <tr>
       <td>Data1</td>
       <td>Data2</td>
   </tr>
</table>

SCOPE AND HEADERS ATTRIBUTES IN TABLES
-utilized so that assistive tech in browser can identify as to which th is attributed to what table data and vise versa

headers

<table>
   <tr>
      <th id="test">column1</th>
 
   </tr>

   <tr>
       <td headers="test">Data1</td>
       <td>Data2</td>
   </tr>
</table>

ROW GROUP ELEMENTS
- specifc multiple rows into either headers, body, and footers

<table>
    <thead>
       <tr></tr>
       <tr></tr>
    <\thead>

    <tbody>
       <tr></tr>
       <tr></tr>
    <\tbody>

    <tfoot>
      <tr></tr>
      <tr></tr>
    </tfoot>
</table>

COLUMN GROUP ELEMENTS

<colgroup></colgroup>
