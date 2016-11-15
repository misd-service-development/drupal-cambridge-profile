University of Cambridge lite install profile
============================================

This install profile contains the basics required for a University of Cambridge Drupal site (such as the University's house style and Raven authentication). It also provide a handful of the most common modules (such as Views); important patches are also applied to some modules where there hasn't been a new stable release.

Installing a new Drupal site
----------------------------

In a fresh copy of Drupal extract the contents of this profile to `/profiles/cambridge_lite/`, then follow the normal Drupal installation process. On the first screen you will see the option to use the Cambridge install profile:

![Select profile](doc/select_profile.png)

(If you have an existing site, presumably using one of Drupal's bundled install profiles, and would like to switch to this install profile, you can [Google how to do it](https://www.google.co.uk/search?q=drupal+switching+install+profiles). It won't configure the site, but can be useful if you would like to use the modules provided by the profile.)

Updating the profile
--------------------

New versions of the profile will be released every couple of months (sooner if there are security fixes), containing updates to modules (including patches), as well as new modules/functionality.

When updating the profile, replace the whole contents of the `/profiles/cambridge_lite/` folder then run Drupal's update process.

You shouldn't normally make changes to the `/profiles/cambridge_lite/` folder (including trying to updates profile-provided modules through Drupal's update manager), as you may run into problems trying to update the profile in the future.

If you do need a different version of a module to what the profile provides, however, you can override it by placing your version in your site's folder (so one of `/sites/all/modules/`, `/sites/default/modules/` or `/sites/www.mysite.cam.ac.uk/modules/`). When the profile is updated to include the new version you should then remove your override and let Drupal revert back to using the profile's version.


List of currently included modules
----------------------------------

There have been requests in earlier versions of the Profile for a full list of supported / included modules in the Profile, so with the release of version 1.7 we are now including this. The list of included modules is as follows:

CTools
Features
Imagecrop
Libraries
Link
Menu Block
Menu Firstchild
Pathauto
Pathauto Persist
Raven (Cambridge authored module)
Token
Views

Cambridge Feature Modules
-------------------------

Cambridge Carousel - Provides the carousel functionality used on the homepage of many Cambridge websites.
Cambridge Image Styles - Provides various image styles (e.g. leading images, carousel sized image, teaser images). 
Cambridge Link - Provides the Link content type.
Cambridge Teasers - Provides a variety of teaser formats as Drupal view modes.



