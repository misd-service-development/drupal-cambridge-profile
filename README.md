University of Cambridge Drupal install profiles
===============================================

There are two different install profiles provided:

- University of Cambridge
- University of Cambridge (lite)

Lite profile
------------

In the lite profile the University of Cambridge theme is enabled and a few standard pieces are set up (eg images styles, front-page carousel).

This profile is useful if you would like full control over how your Drupal site is put together.

To build the lite profile execute:

    drush make --no-core --contrib-destination=. cambridge_lite.make .

And remove the `cambridge.info`, `cambridge.install`, `cambridge.make` and `cambridge.profile` files.

Full profile
------------

The full profile contains all the features of the lite profile, plus additions that helps you to quickly get going: various common modules are enabled and pre-configured to sensible defaults, while other common-but-not-always-used modules are bundled but not enabled.

This profile is useful if you don't mind following established patterns when putting your Drupal site together.

To build the full profile execute:

    drush make --no-core --contrib-destination=. cambridge.make .

And remove the `cambridge_lite.info` and `cambridge_lite.profile` files.
