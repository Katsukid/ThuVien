use utf8;
package Koha::Schema::Result::BorrowerAttributeTypesBranch;

# Created by DBIx::Class::Schema::Loader
# DO NOT MODIFY THE FIRST PART OF THIS FILE

=head1 NAME

Koha::Schema::Result::BorrowerAttributeTypesBranch

=cut

use strict;
use warnings;

use base 'DBIx::Class::Core';

=head1 TABLE: C<borrower_attribute_types_branches>

=cut

__PACKAGE__->table("borrower_attribute_types_branches");

=head1 ACCESSORS

=head2 bat_code

  data_type: 'varchar'
  is_foreign_key: 1
  is_nullable: 1
  size: 10

=head2 b_branchcode

  data_type: 'varchar'
  is_foreign_key: 1
  is_nullable: 1
  size: 10

=cut

__PACKAGE__->add_columns(
  "bat_code",
  { data_type => "varchar", is_foreign_key => 1, is_nullable => 1, size => 10 },
  "b_branchcode",
  { data_type => "varchar", is_foreign_key => 1, is_nullable => 1, size => 10 },
);

=head1 RELATIONS

=head2 b_branchcode

Type: belongs_to

Related object: L<Koha::Schema::Result::Branch>

=cut

__PACKAGE__->belongs_to(
  "b_branchcode",
  "Koha::Schema::Result::Branch",
  { branchcode => "b_branchcode" },
  {
    is_deferrable => 1,
    join_type     => "LEFT",
    on_delete     => "CASCADE",
    on_update     => "RESTRICT",
  },
);

=head2 bat_code

Type: belongs_to

Related object: L<Koha::Schema::Result::BorrowerAttributeType>

=cut

__PACKAGE__->belongs_to(
  "bat_code",
  "Koha::Schema::Result::BorrowerAttributeType",
  { code => "bat_code" },
  {
    is_deferrable => 1,
    join_type     => "LEFT",
    on_delete     => "CASCADE",
    on_update     => "RESTRICT",
  },
);


# Created by DBIx::Class::Schema::Loader v0.07039 @ 2014-07-11 09:26:55
# DO NOT MODIFY THIS OR ANYTHING ABOVE! md5sum:MA/VDd/K/RTgZ9TLy0K1gw


# You can replace this text with custom content, and it will be preserved on regeneration
1;
