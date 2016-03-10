# Room Reservation Alter

## Introduction

Adds custom features for the Robertson Library to use with the Room Reservations module.

## Requirements

This module requires the following modules/libraries:

* [Room Reservations](https://www.drupal.org/project/room_reservations)
* [Views](https://www.drupal.org/project/views)
* [Shibboleth Authentication](https://www.drupal.org/project/shib_auth)
* [Services Views](https://www.drupal.org/project/services_views)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Features and Configuration

### Rewrite login links to Shibboleth.

We wanted to allow 'anonymous' to view the room reservations calendar at `/room_reservations`. However the calendar 
will direct an anonymous user to `/user` to log in. We want to direct them to our Shibboleth endpoint instead. 

`hook_theme` overrides the template for `$theme_registry['room_reservations']['function']` with our custom template. 
The template points the anonymous user to `/Shibboleth.sso/Login` to login with a redirect target pointing to *a custom
php file in drupal root* which bootstraps Drupal before redirecting the user to the page they were trying to access (in
this case, the node creation page for a certain room, date, and time). This redirect script is necessary because of a 
[known bug](https://www.drupal.org/node/1430242) in Shibboleth authentication that prevents a newly-logged in user from 
being immediately authenticated.

#### Configuration

Copy `r.php` from the folder `custom_php` into Drupal root and modify the URLs as necessary. 

### A Custom View Handler to deal with private bookings

Since Services Views [does not use the Views rewriting functionality](https://www.drupal.org/node/1666244), there is a 
custom field handler, "Room Reservation Altered Label", that will display "Booked" if the booking is private or the 
booking name if the booking is not public.

#### Configuration

Create a Services View, and select "Room Reservation Altered Label" as one of the fields. Enable the Services View as 
usual as a REST endpoint.

### Hours Callback

We needed to deliver the opening hours in a machine readable form. A callback is defined at `/room_reservations/hours` 
that returns, in JSON, the next 14 days of opening hours, in the raw array format used by Room Reservations (with first 
and second shifts, open24hours, etc.).


## Maintainers

Current maintainers:

* [Rosie Le Faive](https://github.com/rosiel)

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
