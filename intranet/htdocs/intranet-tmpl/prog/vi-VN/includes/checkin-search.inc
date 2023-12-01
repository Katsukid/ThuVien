[% USE Koha %]
<!-- checkin-search.inc -->
<div id="header_search" role="tabpanel" class="tab-pane active">
 <div class="tab-content">
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' bs_tab_active= 1 %]
 [% INCLUDE 'renew-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]
 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation" class="active">
 <a aria-controls="circ_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Ghi mượn"><i class="fa fa-upload"></i> <span class="tab-title">Ghi mượn</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="renew_search" class="keep_text" data-toggle="tab" href="#renew_search" role="tab" title="Gia hạn"><i class="fa fa-retweet"></i> <span class="tab-title">Gia hạn</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <li role="presentation">
 <a title="Search catalog" href="#catalog_search" aria-controls="catalog_search" role="tab" data-toggle="tab" class="keep_text"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Tìm kiếm danh mục</span></a>
 </li>
 [% END %]
 </ul>
</div><!-- /#header_search -->
<!-- /checkin-search.inc -->
