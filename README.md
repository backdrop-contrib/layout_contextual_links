Layout Contextual Links
===============

This module adds a contextual links drop-down for the layout on all pages.

Installation
------------

Install this module using [the official Backdrop CMS instructions](
  https://docs.backdropcms.org/documentation/extend-with-modules).

Usage
-------------

Once enabled, this will add contextual links for the layout on each page, which
will be seen by users who have the "use contextual links" and "administer
layouts" permissions.

Some themes (e.g., Basis) will cover the contextual links with the admin bar in
their default position. There is a configuration option at
`admin/config/development/layout_contextual_links` to shift the contextual links
downward far enough to clear the admin bar for the default and/or admin themes,
depending on what you're using. The settings page will make recommendations for known themes; for other themes, you can try both settings to see which one gives the best results.

Issues
------

Bugs and feature requests should be reported in [the Issue Queue](https://github.com/backdrop-contrib/layout_contextual_links/issues).

Current Maintainers
-------------------

* [Robert J. Lang](http://github.com/bugfolder)

Credits
-------

- Created for Backdrop by [Robert J. Lang](http://github.com/bugfolder).
- Based on suggestions from [klonos](https://github.com/klonos) and [stpaultim](https://github.com/stpaultim).

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.

